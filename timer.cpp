#include <iostream>
#include <ctime>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;
void getLocal(time_t &Now, struct tm &t);
void printDateandTime(struct tm t);
void printCountdown(struct tm t);

int main() {
    
    time_t Now;
    struct tm t;
    getLocal(Now, t);
    printDateandTime(t);
    printCountdown(t);
    getLocal(Now, t);
    printDateandTime(t);

    return 0;
}

void getLocal(time_t &Now, struct tm &t) {
    Now = time(NULL);
    t = *localtime(&Now);
}
void printDateandTime(struct tm t) {
    cout<< BOLDYELLOW;
    printf("%d-%02d-%02d", t.tm_year+1900, t.tm_mon+1, t.tm_mday);
    printf("  %02d:%02d:%02d", t.tm_hour, t.tm_min, t.tm_sec);
    cout<< RESET << endl;
}
void printCountdown(struct tm t) {
    auto now_ = time(0);
    auto cur_ = time(0);
    cout << BOLDCYAN << "START" << endl;
    cout << BOLDWHITE << 10 << endl;
    for (int i=0; i<10; ) {
        cur_ = time(0);
        if (now_ == cur_-1) {
            cout << BOLDWHITE << 9-i << endl;
            now_ = time(0);
            i++;
        }
    }
    cout << BOLDCYAN << "END" << endl;
    cout << RESET;
}
