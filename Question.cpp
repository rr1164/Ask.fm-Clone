#include "Question.h"
#include <bits/stdc++.h>
using namespace std;
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
    Thread th = threads[thread_index];
    th.set_thread_answer(Thread_answer);
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
Question::~Question() {
    // dtor
}