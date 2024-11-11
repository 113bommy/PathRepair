import sys

s = input()
n = int(input())

dic = {}
for i in s:
    if i in dic:
        dic[i] = dic[i] + 1
    else:
        dic[i] = 1

if len(s) < n:
    print("impossible")
else:
    print(n - len(dic))
