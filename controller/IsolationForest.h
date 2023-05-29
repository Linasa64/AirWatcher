#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <set>
#include <map>
#include <chrono>
#include <queue>
#include <functional>
#include <limits>
#include <stdexcept>
#include <cassert>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
#include <cmath>
#include <iterator>
#include <utility>
#include <limits>
#include <cstddef>
#include <chrono>
#include <memory>
#include <algorithm>
#include <vector>
#include <iterator>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <numeric>
#include <random>
#include <set>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <functional>

class IsolationForest
{
public:
    IsolationForest(int numTrees, int maxDepth)
        : numTrees_(numTrees), maxDepth_(maxDepth), rng_(std::random_device{}())
    {
    }

    void fit(const std::vector<float>& data)
    {
        trees_.clear();

        for (int i = 0; i < numTrees_; ++i)
        {
            std::vector<int> indices(data.size());
            std::iota(indices.begin(), indices.end(), 0);
            std::shuffle(indices.begin(), indices.end(), rng_);

            std::vector<float> subset(data.begin(), data.end());
            subset.resize(indices.size());

            std::sort(subset.begin(), subset.end());
            float minValue = subset.front();
            float maxValue = subset.back();

            trees_.emplace_back(buildTree(subset, indices, minValue, maxValue, 0));
        }
    }

    std::vector<float> getAnomalyScores(const std::vector<float>& data)
    {
        std::vector<float> scores(data.size(), 0.0f);

        for (int i = 0; i < data.size(); ++i)
        {
            for (const auto& tree : trees_)
            {
                scores[i] += getTreePathLength(tree, data[i], 0);
            }

            scores[i] /= numTrees_;
        }

        return scores;
    }

private:
    struct TreeNode
    {
        float splitValue;
        int featureIndex;
        std::unique_ptr<TreeNode> leftChild;
        std::unique_ptr<TreeNode> rightChild;
    };

    std::vector<float>::const_iterator findSplitPoint(const std::vector<float>& data, const std::vector<int>& indices,
                                                      float minValue, float maxValue)
    {
        const auto first = data.begin();
        const auto last = data.end();

        auto it = std::partition_point(first, last, [&](float value) { return value < minValue; });

        if (it == last || *it > maxValue)
        {
            return last;
        }

        return std::lower_bound(it, last, minValue);
    }

    std::unique_ptr<TreeNode> buildTree(const std::vector<float>& data, const std::vector<int>& indices,
                                        float minValue, float maxValue, int depth)
    {
        if (depth >= maxDepth_ || data.size() <= 1)
        {
            return std::make_unique<TreeNode>();
        }

        std::unique_ptr<TreeNode> node = std::make_unique<TreeNode>();

        std::uniform_real_distribution<float> dist(minValue, maxValue);
        node->splitValue = dist(rng_);
        node->featureIndex = std::distance(data.begin(), findSplitPoint(data, indices, node->splitValue, maxValue));

        std::vector<int> leftIndices(indices.begin(), indices.begin() + node->featureIndex);
        std::vector<int> rightIndices(indices.begin() + node->featureIndex, indices.end());

        float leftMinValue = *std::min_element(leftIndices.begin(), leftIndices.end(), [&](int i, int j) { return data[i] < data[j]; });
        float leftMaxValue = *std::max_element(leftIndices.begin(), leftIndices.end(), [&](int i, int j) { return data[i] < data[j]; });
        node->leftChild = buildTree(data, leftIndices, leftMinValue, leftMaxValue, depth + 1);

        float rightMinValue = *std::min_element(rightIndices.begin(), rightIndices.end(), [&](int i, int j) { return data[i] < data[j]; });
        float rightMaxValue = *std::max_element(rightIndices.begin(), rightIndices.end(), [&](int i, int j) { return data[i] < data[j]; });
        node->rightChild = buildTree(data, rightIndices, rightMinValue, rightMaxValue, depth + 1);

        return node;
    }

    int getTreePathLength(const std::unique_ptr<TreeNode>& node, float value, int depth)
    {
        if (!node)
        {
            return depth;
        }

        if (value < node->splitValue)
        {
            return getTreePathLength(node->leftChild, value, depth + 1);
        }
        else
        {
            return getTreePathLength(node->rightChild, value, depth + 1);
        }
    }

    int numTrees_;
    int maxDepth_;
    std::vector<std::unique_ptr<TreeNode>> trees_;
    std::mt19937 rng_;
};



// In the main :


/*
// Example usage
int main() {
    // Create a sample database with sensors and measurements
    Database database;
    std::map<std::string, Sensor*> sensors;
    std::vector<Measurement*> measurements1 = {new Measurement(10.0), new Measurement(12.0), new Measurement(14.0)};
    std::vector<Measurement*> measurements2 = {new Measurement(20.0), new Measurement(22.0), new Measurement(24.0)};
    std::vector<Measurement*> measurements3 = {new Measurement(30.0), new Measurement(32.0), new Measurement(34.0)};
    sensors["Sensor1"] = new Sensor(measurements1);
    sensors["Sensor2"] = new Sensor(measurements2);
    sensors["Sensor3"] = new Sensor(measurements3);
    database.SetSensors(sensors);

    // Create a ControllerComputation object
    ControllerComputation computation;

    // Detect defect sensors and outliers
    std::pair<std::vector<std::shared_ptr<Sensor>>, std::vector<std::vector<float>>> result =
        computation.detectDefectSensorsAndOutliers(database, "2023-01-01", "2023-01-31");

    // Print the defect sensors and their corresponding outliers
    for (size_t i = 0; i < result.first.size(); ++i) {
        std::cout << "Defect Sensor: " << result.first[i]->GetName() << std::endl;
        std::cout << "Outliers: ";
        for (float outlier : result.second[i]) {
            std::cout << outlier << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/