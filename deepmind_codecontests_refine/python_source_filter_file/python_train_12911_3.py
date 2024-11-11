import sys

a = sys.stdin.readline
alphabet = "abcdefghijklmnopqrstuvwxyz"

for i in alphabet:
    print(i + " : " + str(a.lower().count(i)) )