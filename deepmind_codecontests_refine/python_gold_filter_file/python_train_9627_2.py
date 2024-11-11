# https://codeforces.com/problemset/problem/518/B

from collections import Counter

s = input()
mark = s
s = Counter(s)
t = Counter(input())

for i in s.keys():
    if t.get(i):
        temp = s[i]
        s[i] -= t[i]
        t[i] -= temp

yay = 0
whoops = 0
z = 0

for i in s.keys():
    z += max(0, s[i])
    if i.islower() and s[i] > 0 and t.get(i.upper()) and t[i.upper()] > 0:
        if t[i.upper()] >= s[i]:
            whoops += s[i]
        else:
            whoops += t[i.upper()]
    elif i.isupper() and s[i] > 0 and t.get(i.lower()) and t[i.lower()] > 0:
        if t[i.lower()] >= s[i]:
            whoops += s[i]
        else:
            whoops += t[i.lower()]

yay = len(mark) - z

print(yay, whoops)