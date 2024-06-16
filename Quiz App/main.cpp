#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Question {
public:
    string question;
    vector<string> options;
    char correctAnswer;

    Question(string q, vector<string> opts, char ans) {
        question = q;
        options = opts;
        correctAnswer = ans;
    }

    void display() {
        cout << question << endl;
        for (int i = 0; i < options.size(); ++i) {
            cout << char('A' + i) << ". " << options[i] << endl;
        }
    }

    bool isCorrect(char answer) {
        return answer == correctAnswer;
    }
};

int main() {
    vector<Question> quiz = {
        Question("What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 'A'),
        Question("Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 'B'),
        Question("Who wrote 'To Kill a Mockingbird'?", {"Harper Lee", "Mark Twain", "Ernest Hemingway", "F. Scott Fitzgerald"}, 'A'),
        Question("What is the largest ocean on Earth?", {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"}, 'D'),
        Question("Who painted the Mona Lisa?", {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet"}, 'C')
    };

    char userAnswer;
    int score = 0;

    cout << "Welcome to the Quiz!" << endl;
    cout << "Please select the correct option (A, B, C, or D) for each question." << endl << endl;

    for (int i = 0; i < quiz.size(); ++i) {
        cout << "Question " << i + 1 << ":" << endl;
        quiz[i].display();
        cout << "Your answer: ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        if (quiz[i].isCorrect(userAnswer)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer is " << quiz[i].correctAnswer << "." << endl;
        }
        cout << endl;
    }

    cout << "Quiz completed!" << endl;
    cout << "Your score is " << score << " out of " << quiz.size() << "." << endl;

    return 0;
}