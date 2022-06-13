#include <bits/stdc++.h>

#include "User_Question.cpp"
using namespace std;
#define QUESTION 0
#define THREAD 1
#define ANSWER 2
void add_new_user();
void initialize_app();
void update_users_list();
void add_question();
void print_all_users();
void print_asked_questions();
void print_received_questions();
void update_questions_list();
void answer_question();
void delete_question();
map<int, User> users;
map<int, Question> questions;
User current_user_data;
int main() {
    initialize_app();
    srand(time(0));
    int command;
    cout << "Menu: " << endl;
    cout << "    1:Login" << endl;
    cout << "    2:Sign Up" << endl;
    cout << "    3:exit" << endl;
    cout << "Enter number in range 1-3: ";
    while (cin >> command) {
        switch (command) {
            case 1: {
                cout << "Enter user name & password: ";
                string name, password;
                cin >> name >> password;
                int flag = 0;
                for (int i = 0; i < users.size(); i++) {
                    User user = users[i];
                    if (user.get_name() == name && user.get_password() == password) {
                        current_user_data = user;
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    cout << "Couldn't find user " << endl;
                    break;
                }
                cout << "Menu" << endl;
                cout << "   1: print questions to me " << endl;
                cout << "   2: print questions from me" << endl;
                cout << "   3: Answer Question" << endl;
                cout << "   4: Delete Question" << endl;
                cout << "   5: Ask Question" << endl;
                cout << "   6: List System users" << endl;
                cout << "   7: Feed" << endl;
                cout << "   8: Log out" << endl;
                cout << "Enter choice [1-8]: ";
                int comm;
                while (cin >> comm) {
                    initialize_app();
                    if (comm == 1) {
                        print_received_questions();
                    } else if (comm == 2) {
                        print_asked_questions();
                    } else if (comm == 3) {
                        answer_question();
                    } else if (comm == 4) {
                        delete_question();
                    } else if (comm == 5) {
                        add_question();
                    } else if (comm == 6) {
                        print_all_users();
                    } else if (comm == 7) {
                    } else if (comm == 8) {
                        break;
                    }
                    cout << "Menu" << endl;
                    cout << "   1: print questions to me " << endl;
                    cout << "   2: print questions from me" << endl;
                    cout << "   3: Answer Question" << endl;
                    cout << "   4: Delete Question" << endl;
                    cout << "   5: Ask Question" << endl;
                    cout << "   6: List System users" << endl;
                    cout << "   7: Feed" << endl;
                    cout << "   8: Log out" << endl;
                    cout << "Enter choice [1-8] : ";
                }
                break;
            }
            case 2: {
                add_new_user();
                break;
            }
            case 3: {
                return 0;
            }
            default:
                cout << "not supported" << endl;
        }

        cout << "Menu: " << endl;
        cout << "    1:Login" << endl;
        cout << "    2:Sign Up" << endl;
        cout << "    3:exit" << endl;
        cout << "Enter number in range 1-3: ";
    }
    return 0;
}
void initialize_app() {
    update_users_list();
    update_questions_list();
}
bool is_user_null(User user) {
    return user.get_id() ? false : true;
}
pair<int, int> find_thread(int thread_id) {
    int i = 0;
    for (std::map<int, Question>::iterator it = questions.begin(); it != questions.end(); ++it) {
        vector<Thread> threads = it->second.get_threads();
        for (int f = 0; f < threads.size(); f++) {
            if (threads[f].get_thread_id() == thread_id)
                return {it->second.get_question_id(), f};
        }
        i++;
    }
    return {-1, -1};
}
bool escape_string(string& str, string print) {
    vector<int> to_delete;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',') to_delete.push_back(i);
    }

    if (!to_delete.empty()) cout << "deleting commas" << endl;

    for (int i = 0; i < to_delete.size(); i++) {
        str.erase(to_delete[i] - i, 1);
    }

    if (!to_delete.empty()) cout << "new " + print << ": " << str << endl;

    if (str.empty()) {
        cout << print << "  should be at least 1 char long" << endl;
        return false;
    }
    return true;
}

void eraseFileLine(int q_id) {
    string path = "questions.txt";
    std::string line;
    std::ifstream fin(path);
    std::ofstream temp;
    temp.open("temp.txt");
    while (getline(fin, line)) {
        if (line == "") continue;  // Skip blank line
        string question_type, question_id;
        stringstream ss(line);
        getline(ss, question_type, ',');
        getline(ss, question_id, ',');
        if (q_id != stoi(question_id)) temp << line << std::endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char* p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}
void eraseThread(int q_id) {
    string path = "questions.txt";
    std::string line;
    std::ifstream fin(path);
    std::ofstream temp;
    temp.open("temp.txt");
    while (getline(fin, line)) {
        if (line == "") continue;  // Skip blank line
        string question_type,p_q_id, thread_id;
        stringstream ss(line);
        getline(ss, question_type, ',');
        getline(ss, p_q_id, ',');
        getline(ss, thread_id, ',');
        if (stoi(question_type) == 1 && q_id == stoi(thread_id)) continue;
        temp << line << std::endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char* p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}
void print_threads(vector<Thread> threads) {
    for (int f = 0; f < threads.size(); f++) {
        string is_anon = current_user_data.get_anon() ? " " : "!AQ From: " + threads[f].get_from_id();
        cout << "   " << threads[f].get_thread_text() << is_anon
             << " id: " << threads[f].get_thread_id();
        if (!threads[f].get_thread_answer().empty()) {
            cout << " Answer: " << threads[f].get_thread_answer();
        } else {
            cout << " Not Answered YET!!!";
        }
        cout << endl;
    }
}
void print_all_users() {
    for (std::map<int, User>::iterator it = users.begin(); it != users.end(); ++it)
        cout << it->second.get_name() << ' ' << it->second.get_id() << endl;
}
void print_received_questions() {
    User user = users[current_user_data.get_id()];

    vector<Question> received_questions = user.get_received_questions();

    for (int i = 0; i < received_questions.size(); i++) {
        string is_anon = current_user_data.get_anon() ? " " : "!AQ From: " + received_questions[i].get_from_id();
        cout << received_questions[i].get_question_text() << is_anon << " question id: "
             << received_questions[i].get_question_id();
        if (!received_questions[i].get_answer().empty()) {
            cout << " Answer: " << user.get_received_questions()[i].get_answer();
        } else {
            cout << " Not Answered YET!!!";
        }
        cout << endl;

        vector<Thread> threads = received_questions[i].get_threads();
        print_threads(threads);
    }
}
void print_asked_questions() {
    User user = users[current_user_data.get_id()];
    vector<Question> asked_questions = user.get_asked_questions();

    for (int i = 0; i < asked_questions.size(); i++) {
        string is_anon = current_user_data.get_anon() ? " " : "!AQ From: " + asked_questions[i].get_from_id();
        cout << asked_questions[i].get_question_text() << is_anon << " question id: "
             << asked_questions[i].get_question_id();
        if (!asked_questions[i].get_answer().empty()) {
            cout << " Answer: " << user.get_asked_questions()[i].get_answer();
        } else {
            cout << " Not Answered YET!!!";
        }
        cout << endl;

        vector<Thread> threads = asked_questions[i].get_threads();
        print_threads(threads);
    }
}

void add_new_user() {
    string name, email, password;
    string anon;
    char anonymous;
    int id = rand();
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;
    do {
        cout << "Allow Anonymus Questions? [y/n]: ";
        cin >> anonymous;
    } while (!cin.fail() && anonymous != 'y' && anonymous != 'n');

    if (!escape_string(email, "email") || !escape_string(password, "password") || !escape_string(name, "name"))
        return;

    ofstream MyFile("users.txt", ios_base::app);
    MyFile << endl
           << name << ',' << email << ',' << password << ',' << anonymous << ',' << id;
    MyFile.close();
}
void add_question() {
    cout << "Enter user id or -1 to cancel: ";
    int ask_user_id;

    cin >> ask_user_id;

    if (ask_user_id == -1) return;

    if (current_user_data.get_id() == ask_user_id) {
        cout << "you can't ask yourself" << endl;
        return;
    }

    User& user_to = users[ask_user_id];
    if (is_user_null(user_to)) {
        cout << "user doesn't exist " << endl;
        return;
    }

    if (!user_to.get_anon()) cout << "Note: user doesn't allow Anonymus questions" << endl;

    int question_type;
    string question_text;
    int parent_q_id;
    cout << "For thread question: Enter question id or -1 for new question: ";
    cin >> parent_q_id;

    question_type = parent_q_id == -1 ? QUESTION : THREAD;
    if (question_type == THREAD && !questions[parent_q_id].get_question_id()) {
        cout << "invalid question " << endl;
        return;
    }
    cout << "Enter question Text: ";

    cin.ignore();

    getline(cin, question_text);

    int question_id = rand();

    if (!escape_string(question_text, "text"))
        return;

    ofstream MyFile("questions.txt", ios_base::app);
    if (question_type == QUESTION) {
        MyFile << endl
               << question_type << ',' << question_id << ',' << question_text << ',' << current_user_data.get_id() << ',' << ask_user_id;
    } else {
        MyFile << endl
               << question_type << ',' << parent_q_id << ',' << question_id << ',' << question_text << ',' << current_user_data.get_id() << ',' << ask_user_id;
    }
    MyFile.close();
}
void answer_question() {
    cout << "Enter question id or -1 to cancel: ";
    int question_id;

    cin >> question_id;

    if (question_id == -1) return;

    Question asked_question = questions[question_id];
    // make sure question is actually asked to user
    pair<int, int> is_thread = find_thread(question_id);
    bool is_question = asked_question.get_question_id() &&
                       asked_question.get_to_id() == current_user_data.get_id() &&
                       !asked_question.get_answer().empty();
    bool is_Thread = is_thread.first != -1 &&
                     questions[is_thread.first].get_to_id() == current_user_data.get_id() &&
                     !questions[is_thread.first].get_answer().empty();
    if (!is_question && !is_Thread) {
        cout << "question id/thread id not found or question not asked to you or question already answered"
             << endl;
        return;
    }

    cout << "Enter answer: ";
    cin.ignore();

    string answer_text;
    getline(cin, answer_text);

    if (!escape_string(answer_text, "text"))
        return;

    ofstream MyFile("questions.txt", ios_base::app);
    if (!is_Thread)
        MyFile << endl
               << ANSWER << ',' << question_id << ',' << answer_text << ',' << asked_question.get_from_id() << ',' << current_user_data.get_id();
    else
        MyFile << endl
               << ANSWER << ',' << question_id << ',' << answer_text << ',' << questions[is_thread.first].get_from_id() << ',' << current_user_data.get_id();

    MyFile.close();
}
void delete_question() {
    cout << "Enter Question id or -1 to cancel: ";
    int q_id;
    cin >> q_id;
    Question asked_question = questions[q_id];
    pair<int, int> is_thread = find_thread(q_id);
    bool is_question = asked_question.get_question_id() &&
                       asked_question.get_from_id() == current_user_data.get_id() &&
                       !asked_question.get_answer().empty();
    bool is_Thread = is_thread.first != -1 &&
                     questions[is_thread.first].get_from_id() == current_user_data.get_id() &&
                     !questions[is_thread.first].get_answer().empty();
    if (is_Thread || is_question) {
        if (is_question) 
            eraseFileLine(q_id);
        else
            eraseThread(q_id);
         cout << "deleted sucessfully " << endl;
   } else {
        cout << "Question Id not found " << endl;
    }
}
void update_questions_list() {
    questions.clear();
    ifstream inFile("questions.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (line == "") continue;  // Skip blank line
            stringstream ss(line);

            string Question_type;

            getline(ss, Question_type, ',');

            int question_type = stoi(Question_type);

            if (question_type == ANSWER || question_type == QUESTION) {
                string Question_id, question_text, From_id, To_id;
                getline(ss, Question_id, ',');
                getline(ss, question_text, ',');
                getline(ss, From_id, ',');
                getline(ss, To_id, ',');
                int question_id = stoi(Question_id), from_id = stoi(From_id), to_id = stoi(To_id);
                if (question_type == ANSWER) {
                    Question& question = questions[question_id];
                    // answer is to thread not to a question
                    if (!question.get_question_id()) {
                        pair<int, int> thread_index = find_thread(question_id);
                        assert(thread_index.first != -1);
                        int p_q_id = thread_index.first, th_index = thread_index.second;
                        questions[p_q_id].answer_thread(th_index, question_text);
                        vector<Question>& qs = users[from_id].update_asked_questions();
                        bool flag = 0;
                        for (int i = 0; i < qs.size(); i++) {
                            vector<Thread>& qs_threads = qs[i].update_threads();
                            for (int f = 0; f < qs_threads.size(); f++) {
                                if (qs_threads[f].get_thread_id() == question_id) {
                                    qs_threads[f].set_thread_answer(question_text);
                                    flag = 1;
                                    break;
                                }
                            }
                            if (flag) break;
                        }
                        assert(flag == 1);
                        vector<Question>& qs2 = users[to_id].update_received_questions();
                        flag = 0;
                        for (int i = 0; i < qs2.size(); i++) {
                            vector<Thread>& qs_threads = qs2[i].update_threads();
                            for (int f = 0; f < qs_threads.size(); f++) {
                                if (qs_threads[f].get_thread_id() == question_id) {
                                    qs_threads[f].set_thread_answer(question_text);
                                    flag = 1;
                                    break;
                                }
                            }
                            if (flag) break;
                        }
                        assert(flag == 1);
                        continue;
                    }
                    question.set_answer(question_text);
                    vector<Question> qs = users[from_id].update_asked_questions();
                    bool flag = 0;
                    for (int i = 0; i < qs.size(); i++) {
                        if (qs[i].get_question_id() == question_id) {
                            users[from_id].set_asked_question_answer(i, question_text);
                            flag = 1;
                            break;
                        }
                    }
                    assert(flag == 1);
                    vector<Question> qs2 = users[to_id].update_received_questions();
                    flag = 0;
                    for (int i = 0; i < qs2.size(); i++) {
                        if (qs2[i].get_question_id() == question_id) {
                            users[to_id].set_recieved_question_answer(i, question_text);
                            flag = 1;
                            break;
                        }
                    }
                    assert(flag == 1);
                } else if (question_type == QUESTION) {
                    Question q{question_type, question_id,
                               question_text, from_id, to_id};
                    questions[question_id] = q;
                    users[from_id].insert_asked_question(q);
                    users[to_id].insert_recieved_question(q);
                }
            }
            // reading a Thread
            else {
                string Parent_q_id, Thread_id, thread_text, From_id, To_id;

                getline(ss, Parent_q_id, ',');
                getline(ss, Thread_id, ',');
                getline(ss, thread_text, ',');
                getline(ss, From_id, ',');
                getline(ss, To_id, ',');
                int from_id = stoi(From_id), to_id = stoi(To_id), thread_id = stoi(Thread_id), parent_q_id = stoi(Parent_q_id);

                Thread thread(thread_id, parent_q_id, thread_text, from_id, to_id);
                questions[parent_q_id].insert_new_Thread(thread);

                vector<Question>& asked_qs = users[from_id].update_asked_questions();
                // loop to search for the parent question id
                for (int j = 0; j < asked_qs.size(); j++) {
                    if (asked_qs[j].get_question_id() == parent_q_id) {
                        asked_qs[j].insert_new_Thread(thread);
                        break;
                    }
                }

                vector<Question>& recieved_qs = users[to_id].update_received_questions();
                for (int j = 0; j < recieved_qs.size(); j++) {
                    if (recieved_qs[j].get_question_id() == parent_q_id) {
                        recieved_qs[j].insert_new_Thread(thread);
                        break;
                    }
                }
            }
        }
    }
}
void update_users_list() {
    users.clear();
    ifstream inFile("users.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (line == "") continue;  // Skip blank line
            stringstream ss(line);

            string name, email, password, s_anonymus, user_Id;

            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, password, ',');
            getline(ss, s_anonymus, ',');
            getline(ss, user_Id, ',');
            int user_id = stoi(user_Id);
            users[user_id] = {user_id, name, email, password, s_anonymus == "y" ? 1 : 0};
        }
    }
}