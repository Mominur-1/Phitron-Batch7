// https://www.hackerrank.com/contests/mid-term-a-introduction-to-c-for-dsa-a-batch-07/challenges/who-is-it-4

#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    int id;
    char name[105];
    char section;
    int marks;
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Student best;

        for (int i = 0; i < 3; ++i)
        {
            Student st;
            cin >> st.id >> st.name >> st.section >> st.marks;

            // if it's first class then put it in
            best = (!i) ? st : ((st.marks > best.marks || (st.marks == best.marks && st.id < best.id)) ? st : best);

        }

        cout << best.id << " " << best.name << " " << best.section << " " << best.marks << endl;
    }

    return 0;
}