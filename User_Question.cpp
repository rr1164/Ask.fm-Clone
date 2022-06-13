#include "User_Question.h"
using namespace std;
User::User(int theId, string theName, string theEmail, string thePassword, bool theAnon) {
    set_id(theId);
    set_name(theName);
    set_email(theEmail);
    set_password(thePassword);
    set_anon(theAnon);
}
User::User(){
    set_id(0);
    set_anon(0);
    name.clear();
    email.clear();
    password.clear();
}
string User::get_email() const {
    return email;
}
vector<Question> User::get_received_questions() const {
    return receieved_questions;
}
vector<Question> User::get_asked_questions() const {
    return asked_questions;
}
int User::get_id() const {
    return id;
}
string User::get_name() const {
    return name;
}
string User::get_password() const {
    return password;
}
bool User::get_anon() const {
    return anon;
}

void User::set_id(int newId) {
    id = newId;
    return;
}
void User::set_email(string newEmail) {
    email = newEmail;
    return;
}
void User::set_recieved_question_answer(int index, string answer) {
    assert(index >= 0 && index < receieved_questions.size());
    receieved_questions[index].set_answer(answer);
}
vector<Question>& User::update_received_questions() {
    return receieved_questions;
}
vector<Question>& User::update_asked_questions() {
    return asked_questions;
}
void User::set_asked_question_answer(int index, string answer) {
    assert(index >= 0 && index < asked_questions.size());
    asked_questions[index].set_answer(answer);
}
void User::insert_asked_question(Question q) {
    asked_questions.push_back(q);
}
void User::insert_recieved_question(Question q) {
    receieved_questions.push_back(q);
}

void User::set_name(string newName) {
    name = newName;
    return;
}

void User::set_password(string newPassword) {
    password = newPassword;
    return;
}
void User::set_anon(bool newAnon) {
    anon = newAnon;
    return;
}

Question::Question(int Question_type, int Question_id, string Question_text, int From_id, int To_id) {
    set_question_type(Question_type);
    set_question_id(Question_id);
    set_from_id(From_id);
    set_to_id(To_id);
    text = Question_text;
}
Question::Question(int Question_type, int Question_id, string Question_text, int From_id, int To_id, string Answer) {
    set_question_type(Question_type);
    set_question_id(Question_id);
    set_from_id(From_id);
    set_to_id(To_id);
    text = Question_text;
    set_answer(Answer);
}
Question::Question(){
    set_question_type(0);
    set_question_id(0);
    set_from_id(0);
    set_to_id(0);
    answer.clear();
    text.clear();
}
void Question::insert_new_Thread(Thread newThread) {
    threads.push_back(newThread);
}
void Question::answer_thread(int thread_index,string Thread_answer) {
    assert(thread_index >= 0 && thread_index < threads.size());
    threads[thread_index].set_thread_answer(Thread_answer);
}

void Question::set_question_id(int theId) {
    question_id = theId;
}
void Question::set_answer(string Answer) {
    answer = Answer;
}
void Question::set_from_id(int theId) {
    from_id = theId;
}
void Question::set_question_type(int q_type) {
    question_type = q_type;
}
void Question::set_to_id(int theId) {
    to_id = theId;
}
int Question::get_question_id() const {
    return question_id;
}
int Question::get_from_id() const {
    return from_id;
}
int Question::get_to_id() const {
    return to_id;
}
int Question::get_question_type() const {
    return question_type;
}
vector<Thread>& Question::update_threads() {
    return threads;
}
vector<Thread> Question::get_threads() const {
    return threads;
}
string Question::get_question_text() const {
    return text;
}
string Question::get_answer() const {
    return answer;
}
int Thread::get_from_id() const {
    return from_id;
}
int Thread::get_thread_id() const {
    return thread_id;
}
int Thread::get_parent_question_id() const {
    return parent_question_id;
}
string Thread::get_thread_answer() const {
    return thread_answer;
}
string Thread::get_thread_text() const {
    return thread_text;
}
void Thread::set_thread_answer(string Threadanswer) {
    thread_answer = Threadanswer;
}
Thread::Thread(int Thread_id, int Parent_question_id, string Thread_text, string Thread_answer,
               int From_id, int To_id) {
    thread_id = Thread_id;
    parent_question_id = Parent_question_id;
    thread_text = Thread_text;
    thread_answer = Thread_answer;
    from_id = From_id;
    to_id = To_id;
}
Thread::Thread(int Thread_id, int Parent_question_id, string Thread_text,
               int From_id, int To_id) {
    thread_id = Thread_id;
    parent_question_id = Parent_question_id;
    thread_text = Thread_text;
    from_id = From_id;
    to_id = To_id;
}
Question::~Question() {
    // dtor
}
User::~User() {
    // dtor
}
