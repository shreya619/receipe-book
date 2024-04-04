#include <iostream>
#include <cstring>

class Recipe {
private:
    char* name;
    char* ingredients;
    char* instructions;
    char* category;

public:
    Recipe(const char* recipeName, const char* recipeIngredients, const char* recipeInstructions, const char* recipeCategory)
        : name(nullptr), ingredients(nullptr), instructions(nullptr), category(nullptr) {
        setName(recipeName);
        setIngredients(recipeIngredients);
        setInstructions(recipeInstructions);
        setCategory(recipeCategory);
    }

    ~Recipe() {
        // Deallocate memory
        delete[] name;
        delete[] ingredients;
        delete[] instructions;
        delete[] category;
    }

    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    void setIngredients(const char* newIngredients) {
        delete[] ingredients;
        ingredients = new char[strlen(newIngredients) + 1];
        strcpy(ingredients, newIngredients);
    }

    void setInstructions(const char* newInstructions) {
        delete[] instructions;
        instructions = new char[strlen(newInstructions) + 1];
        strcpy(instructions, newInstructions);
    }

    void setCategory(const char* newCategory) {
        delete[] category;
        category = new char[strlen(newCategory) + 1];
        strcpy(category, newCategory);
    }

    void displayRecipe() const {
        std::cout << "\n=== Recipe Details ===\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Ingredients: " << ingredients << "\n";
        std::cout << "Instructions: " << instructions << "\n";
        std::cout << "Category: " << category << "\n";
    }
};

class RecipeBook {
private:
    Recipe** recipes;
    int numRecipes;

public:
    RecipeBook() : recipes(nullptr), numRecipes(0) {}

    ~RecipeBook() {
        for (int i = 0; i < numRecipes; ++i) {
            delete recipes[i];
        }
        delete[] recipes;
    }

    void addRecipe(const Recipe& newRecipe) {
        Recipe** newRecipes = new Recipe*[numRecipes + 1];

        for (int i = 0; i < numRecipes; ++i) {
            newRecipes[i] = new Recipe(*recipes[i]);
        }

        newRecipes[numRecipes] = new Recipe(newRecipe);

        for (int i = 0; i < numRecipes; ++i) {
            delete recipes[i];
        }
        delete[] recipes;

        recipes = newRecipes;
        ++numRecipes;
    }

    void displayRecipes() const {
        std::cout << "\n=== Recipe Book ===\n";
        for (int i = 0; i < numRecipes; ++i) {
            recipes[i]->displayRecipe();
        }
    }
};

int main() {
    RecipeBook recipeBook;

    Recipe pastaRecipe("Spaghetti Carbonara", "Spaghetti, Eggs, Bacon, Parmesan Cheese, Black Pepper",
                       "Cook spaghetti. Mix eggs, bacon, and cheese. Combine with cooked spaghetti. Add black pepper to taste.", "Pasta");
    recipeBook.addRecipe(pastaRecipe);

    Recipe cakeRecipe("Chocolate Cake", "Flour, Sugar, Cocoa Powder, Eggs, Milk, Butter",
                      "Mix dry ingredients. Add wet ingredients. Bake in the oven.", "Dessert");
    recipeBook.addRecipe(cakeRecipe);

    recipeBook.displayRecipes();

    return 0;
}
