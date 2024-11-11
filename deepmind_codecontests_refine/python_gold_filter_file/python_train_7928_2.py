from collections import defaultdict
n = int(input())
word = input()
d = defaultdict(list)
for i in range(n):
    d[word[i]].append(i)
# print(d)
for i in range(int(input())):
    pre = input()
    c = {}
    for i in pre:
        if i not in c:
            c[i] = 1
        else:
            c[i]+=1
    f = -1
    for i in c:
        t = d[i]
        t = t[c[i]-1]
        f = max(f,t)
    print(f+1)