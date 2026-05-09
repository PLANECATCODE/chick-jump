#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

void slep(double seconds) {
    this_thread::sleep_for(chrono::duration<double>(seconds));
}

void clear() {
    system("clear");
}

// Game logic moved into a function so we can call it multiple times
void playGame() {
    clear();
    cout << "=== 🐥 CHICK JUMP — THE EGG GAME 🥚 ===" << endl;
    slep(1);

    cout << "game loading (press W to jump)" << endl;
    slep(1);
    clear();
    cout << "=" << endl; slep(1);
    clear();
    cout << "==" << endl; slep(1);
    clear();
    cout << "===" << endl; slep(1);
    clear();
    cout << "====" << endl; slep(1);
    clear();
    cout << "=====" << endl; slep(1);
    clear();
    cout << "======" << endl; slep(1);
    clear();
    cout << "========" << endl; slep(1);
    clear();
    cout << "A MIAU Production" << endl;
    slep(1);
    clear();

    cout << "\033[4m🐥          🥚\033[0m\n"; slep(1);
    clear();
    cout << "\033[4m 🐥         🥚\033[0m\n"; slep(1);
    clear();
    cout << "\033[4m  🐥        🥚\033[0m\n"; slep(1);
    clear();
    cout << "\033[4m   🐥       🥚\033[0m\n"; slep(1);
    clear();
    cout << "\033[4m    🐥      🥚\033[0m\n"; slep(1);
    clear();
    cout << "\033[4m     🐥     🥚\033[0m\n"; slep(1);
    clear();
    cout << "\033[4m      🐥    🥚\033[0m\n"; slep(1);
    clear();
    cout << "\033[4m       🐥   🥚\033[0m\n"; slep(1);
    clear();
    cout << "\033[4m         🐥 🥚\033[0m\n"; slep(1);
    clear();

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    int result = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

    char key = 0;
    if (result > 0) {
        key = cin.get();
    }

    clear();

    if (key == 'w' || key == 'W') {
        cout << "            🐥" << endl;
        cout << "            🥚" << endl;
        cout << "\033[4m🐥          🥚\033[0m\n";
        cout << "\n🎉 YAY! YOU SAVED THE EGG! YOU WIN! 🎉" << endl;
    } else {
        cout << "\033[4m            🐥🐣" << endl;
        cout << "\033[4m🐥          🥚\033[0m\n";
        cout << "\n💥 OOPS! YOU LOST! 💥" << endl;
        cout << "You broke the egg and woke up the baby chick..." << endl;
        cout << "Better luck next time!" << endl;
    }
}

int main() {
    char replay;
    int times;

    do {
        playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> replay;

        if (replay == 'y' || replay == 'Y') {
            cout << "How many times? ";
            cin >> times;

            for (int i = 1; i < times; i++) {
                playGame();
            }
        }

    } while (replay == 'y' || replay == 'Y');

    cout << "Thanks for playing! 🐥" << endl;
    return 0;
}