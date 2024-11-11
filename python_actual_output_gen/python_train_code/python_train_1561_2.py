#!/usr/bin/env pypy
n = str(input())
n = n.lower()
vowel = "aeiou"
consonants = "bcdfghjklmnpqrstvwxyz"
l = []
for i in n:
    if(i in consonants):
        l.append("."+i)
l = "".join(l)
print(l)


