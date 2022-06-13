#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
class Question;
class Thread;
class User
{
public:
    User(int theId, std::string theName, std::string theEmail, std::string thePassword, bool theAnon);
    User();
    std::string get_name() const;

    int get_id() const;

    bool get_anon() const;

    std::vector<Question> get_received_questions() const;

    std::vector<Question> get_asked_questions() const;
    
    std::vector<Question>& update_asked_questions();
    
    std::vector<Question>& update_received_questions();

    std::string get_email() const;

    std::string get_password() const;

    void set_id(int newId);

    void set_email(std::string newEmail);

    void set_name(std::string newName);

    void set_recieved_question_answer(int index,std::string answer);

    void set_asked_question_answer(int index,std::string answer);

    void set_password(std::string newPassword);

    void set_anon(bool newAnon);

    void insert_recieved_question(Question q);

    void insert_asked_question(Question q);
   virtual ~User();

protected:
private:
    int id;
    std::string name;
    std::string email;
    std::string password;
    bool anon;
    std::vector<Question> asked_questions;
    std::vector<Question> receieved_questions;
};
class Question
{
public:
    Question(int question_type,int question_id,std::string question_text,int from_id,int to_id);
    Question(int Question_type,int Question_id,std::string Question_text,int From_id,int To_id,std::string Answer);
    Question();
    int get_question_type() const;

    int get_question_id() const;
    
    int get_from_id() const;

    int get_to_id() const;

    std::string get_answer() const;

    std::string get_question_text() const;

    void set_question_id(int theId);
    
    void set_answer(std::string Answer);

    void set_from_id(int theId);

    void set_to_id(int theId);

    void set_question_type  (int q_type);

    std::vector<Thread> get_threads() const;

    std::vector<Thread>& update_threads();

    void insert_new_Thread(Thread newThread);
    
    void answer_thread(int thread_index,std::string Thread_answer);

    virtual ~Question();

protected:
private:
    int question_type;
    int question_id;
    std::vector<Thread> threads;
    std::string text;
    std::string answer;
    int from_id;
    int to_id;
};
class Thread{
public:
    Thread(int Thread_id,int Parent_question_id,std::string Thread_text,std::string Thread_answer,
    int From_id,int To_id);
    
    Thread(int Thread_id,int Parent_question_id,std::string Thread_text,
    int From_id,int To_id);
    
    int get_parent_question_id() const;
    
    int get_from_id() const;

    int get_to_id() const;
    
    int get_thread_id() const;
    
    std::string get_thread_text() const;
    
    std::string get_thread_answer() const;

    void set_thread_answer(std::string Threadanswer);
protected:
private:
    int thread_id;
    int parent_question_id;
    std::string thread_text;
    std::string thread_answer;
    int from_id;
    int to_id;
};
#endif
