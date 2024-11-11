from collections import Counter
n=int(input())
v=list(map(int, input().split()))
v1=Counter(v[::2])
v2=Counter(v[1::2])
c1=v1.most_common()+[(0, 0)]
c2=v2.most_common()+[(0, 0)]
if c1[0][0]==c2[0][0]:
    ans=max(c1[1][1]+c2[0][1], c1[0][1]-c2[1][1])
    print(n-ans)
else:
    print(n-c1[0][1]-c2[0][1])