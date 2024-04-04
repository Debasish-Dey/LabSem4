#include <iostream>
#include <vector>
using namespace std;

struct MooreState {
    int output;
    vector<pair<int, int>> transitions; 
};

struct MealyState {
    int output;
    vector<pair<int, pair<int, int>>> transitions; 
};

vector<MealyState> mooreToMealy(vector<MooreState>& moore) {
    int num_states = moore.size();
    vector<MealyState> mealy(num_states);
    for (int i = 0; i < num_states; i++) {
        mealy[i].output = moore[i].output;
    }
    for (int i = 0; i < num_states; i++) {
        for (auto& transition : moore[i].transitions) {
            int input = transition.first;
            int next_state = transition.second;
            int next_state_output = moore[next_state].output;
            mealy[i].transitions.push_back(make_pair(input, make_pair(next_state, next_state_output)));
        }
    }
    return mealy;
}

void printMealyTransitions(const vector<MealyState>& mealy) {
    for (auto& state : mealy) {
        cout << "State " << state.output << " transitions:" << endl;
        for (auto& transition : state.transitions) {
            int input = transition.first;
            int next_state = transition.second.first;
            int next_state_output = transition.second.second;
            cout << "\tInput " << input << " goes to State " << next_state << " with output " << next_state_output << endl;
        }
    }
}

int main() {
    int num_states;
    cout << "Enter the number of states: ";
    cin >> num_states;
    vector<MooreState> moore(num_states);
    for (int i = 0; i < num_states; i++) {
        cout << "Enter the output for state " << i << ": ";
        cin >> moore[i].output;
        int num_transitions;
        cout << "Enter the number of transitions for state " << i << ": ";
        cin >> num_transitions;
        for (int j = 0; j < num_transitions; j++) {
            int input, next_state;
            cout << "Enter the input and next state for transition " << j << " of state " << i << ": ";
            cin >> input >> next_state;
            moore[i].transitions.push_back(make_pair(input, next_state));
        }
    }
    vector<MealyState> mealy = mooreToMealy(moore);
    printMealyTransitions(mealy);
    return 0;
}