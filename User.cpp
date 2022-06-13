#include "User.h"
#include "Question.h"
#include "bits/stdc++.h"
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

User::~User() {
    // dtor
}
