#ifndef THREAD_H
#define THREAD_H
#include <string>
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