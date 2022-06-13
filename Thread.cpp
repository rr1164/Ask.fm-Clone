#include "Thread.h"
#include <bits/stdc++.h>
using namespace std;
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
