from collections import Counter
n=int(input())
v=list(map(int,input().split()))
if len(set(v))==1:print(n//2)
else:
    v.extend([0,0])
    voc=Counter(v[::2]).most_common(2)
    vec=Counter(v[1::2]).most_common(2)
    if len(voc)==len(vec)==1:print(0)
    elif voc[0][0]==vec[1][0]:print(n-max(voc[0][1]+vec[1][1],voc[1][1]+vec[0][1]))
    else:print(n-voc[0][1]-vec[0][1])