# coding: utf-8
string = input()
if string[0].islower():
    if len(string)==1 or string[1:-1].isupper():
        string = string.capitalize()
elif string.isupper():
    string = string.lower()
    
print(string)
