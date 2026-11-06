// Challenge 2: Alexa, Tell Me a Joke
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
using namespace std;

vector<string> loadJokes(const string& filename) {
    ifstream file(filename);
    vector<string> jokes;
    string line;
    if (!file) {
        cerr << "Could not open " << filename << ".\n";
        return jokes;
    }
    while (getline(file, line)) {
        if (line.find('?') != string::npos) jokes.push_back(line);
    }
    return jokes;
}

void tellJoke(const string& joke) {
    size_t separator = joke.find('?');
    cout << joke.substr(0, separator + 1) << '\n';
    cout << "Press Enter for the punchline...";
    string response;
    getline(cin, response);
    string punchline = joke.substr(separator + 1);
    size_t firstCharacter = punchline.find_first_not_of(" \t");
    if (firstCharacter != string::npos) punchline.erase(0, firstCharacter);
    cout << punchline << "\n\n";
}

int main() {
    vector<string> jokes = loadJokes("randomJokes.txt");
    if (jokes.empty()) return 1;
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<size_t> pick(0, jokes.size() - 1);
    cout << "Type 'Alexa, tell me a joke' or 'quit' to finish.\n";
    string command;
    while (true) {
        cout << "> ";
        if (!getline(cin, command) || command == "quit" || command == "Quit") break;
        if (command == "Alexa, tell me a joke") {
            tellJoke(jokes[pick(generator)]);
        } else {
            cout << "Please use the exact phrase or type 'quit'.\n";
        }
    }
    cout << "Goodbye!\n";
    return 0;
}
