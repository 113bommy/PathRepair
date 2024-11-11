"""
Brandt Smith, Lemuel Gorion and Peter Haddad

codeforces.com

Problem 300A
"""

n = input()

l = [int(x) for x in input().split(' ')]

arr = sorted(l)
neg = [arr.pop(0)]

if arr[-1] > 0:
        pos = [arr.pop()]
else:
        pos = [arr.pop(0), arr.pop(0)]

for i in neg, pos, arr:
        print(len(i), end = ' ')
        for k in i:
                print(k,end = ' ')

        print()








    
