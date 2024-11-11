from collections import Counter
n,m=map(int,input().split())
l=list(map(int,input().split()))
c=Counter(l)
if len(c) == n :
    print(min(c.values()))
else :
    print("0")