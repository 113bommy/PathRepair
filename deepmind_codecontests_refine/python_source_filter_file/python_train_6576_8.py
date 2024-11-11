import sys
input = sys.stdin.readline
from collections import Counter

Q=int(input())
for testcases in range(Q):
    s=input().strip()
    t=input().strip()
    p=input().strip()

    L=len(s)
    ind=0

    for te in t:
        if te==s[ind]:
            ind+=1
        if ind==L:
            break

    if ind != L:
        print("NO")
        break

    C=Counter(s)+Counter(p)
    CT=Counter(t)

    #print(s,p,t,C,CT)

    for ct in CT:
        if CT[ct]>C[ct]:
            print("NO")
            break
    else:
        print("YES")

    
