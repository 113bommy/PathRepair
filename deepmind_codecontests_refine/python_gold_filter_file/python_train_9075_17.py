from collections import Counter, defaultdict

BS="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def to_base(s, b):
    res = ""
    while s:
        res+=BS[s%b]
        s//= b
    return res[::-1] or "0"
alpha = "abcdefghijklmnopqrstuvwxyz"
from math import floor, ceil



s = input()

a = s.count("7")
b = s.count("4")
ab  = s.count("47")
ba = s.count("74")
d = {"7":a, "4":b, "47":ab, "74":ba}

flag = False
m = 1
ans = None
for i in d.keys():
    if d[i] >= m:
        if ans is None:
            m = d[i]
            ans = i
            flag= True
        elif i < ans:
            m = d[i]
            ans = i
            flag= True

if not flag:
    print(-1)
else:
    print(ans)