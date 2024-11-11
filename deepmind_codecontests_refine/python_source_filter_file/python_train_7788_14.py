N=int(input())
*V,=map(int,input().split())
import collections

c1=collections.Counter(V[0::2]).most_common()
c2=collections.Counter(V[1::2]).most_common()
c1.append([0,0])
c2.append([0,0])
if c1[0][0]!=c2[0][0]:
    print(N-c1[0][1]-c2[0][1])
else:
    print(min(N-c1[0][1]-c2[1][0],N-c1[1][0]-c2[0][1]))