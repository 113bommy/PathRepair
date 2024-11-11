#!/bin/python3

def myfunc(st):
    return st.replace(st[0], st[0].upper())



if __name__ == '__main__':

    s = input()
    print(myfunc(s))



