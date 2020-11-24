//
// Created by Aleksei Kozharin on 24.11.2020.
//
#include <string>
#include <iostream>
#include <utility>

using namespace std;

void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);

class INotifier {
public:
    virtual void Notify(const string& message) = 0;
};

class SmsNotifier: public INotifier {
public:
    explicit SmsNotifier(string  number): number_(std::move(number)) {}
    void Notify(const string& message) override {
        SendSms(number_, message);
    }
private:
    const string number_;
};

class EmailNotifier: public INotifier {
public:
    explicit EmailNotifier(string email): email_(std::move(email)) {}
    void Notify(const string& message) override {
        SendEmail(email_, message);
    }
private:
    const string email_;
};
