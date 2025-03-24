#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available_supplies(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> recipe_to_ingredients;
        unordered_map<string, int> visited;
        vector<string> result;
        
        // Build the recipe-to-ingredients mapping
        for (size_t i = 0; i < recipes.size(); i++) {
            recipe_to_ingredients[recipes[i]] = ingredients[i];
        }
        
        // Lambda to check if we can make the recipe
        function<bool(string)> can_make = [&](string recipe) {
            if (visited.count(recipe)) {
                return visited[recipe] == 1;
            }
            
            if (available_supplies.count(recipe)) {
                return true;
            }
            
            if (!recipe_to_ingredients.count(recipe)) {
                return false;
            }
            
            visited[recipe] = 0; // Mark as in-progress
            
            // Check if all ingredients are available
            for (const string& ingredient : recipe_to_ingredients[recipe]) {
                if (!can_make(ingredient)) {
                    visited[recipe] = -1; // Mark as not possible
                    return false;
                }
            }
            
            visited[recipe] = 1; // Mark as done
            result.push_back(recipe);
            return true;
        };
        
        // Check all recipes
        for (const string& recipe : recipes) {
            can_make(recipe);
        }
        
        return result;
    }
};
