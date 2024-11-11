from collections import Counter,defaultdict
n=int(input())
s=str(input())
a=defaultdict(list)
for i in range(len(s)):
    a[s[i]].append(i)
for j in range(int(input())):
    t=Counter(input())
    #print(t)
    p=max([a[o][t[o]-1]for o in t])
    print(p+1)