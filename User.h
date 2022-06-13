#ifndef USER_H
#define USER_H  
#include "string"
#include "vector"
class Question;
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
#endif