N=int(input())
*V,=map(int,input().split())
import collections import Counter

c1=Counter(V[0::2]).most_common()+[(0,0)]
c2=Counter(V[1::2]).most_common()+[(0,0)]
if c1[0][0]!=c2[0][0]:
    print(N-c1[0][1]-c2[0][1])
else:
    print(min(N-c1[0][1]-c2[1][1],N-c1[1][1]-c2[0][1]))