#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <vector>
class Thread;
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
#endif