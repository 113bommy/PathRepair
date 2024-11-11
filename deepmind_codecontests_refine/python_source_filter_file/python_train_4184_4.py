import sys
from collections import Counter
input=sys.stdin.readline

t=str(input())[:-1]
if len(t)==1:
    for i in range(10):
        print(*([-1]*10))
else:
    diff=[(int(t[k+1])-int(t[k]))%10 for k in range(len(t)-1)]
    cnt=Counter(diff)
    arr=[[0 for _ in range(10)] for _ in range(10)]
    for x in range(10):
        for y in range(10):
            d={}
            for i in range(10):
                for j in range(10):
                    if i+j!=0:
                        d[(x*i+y*j)%10]=min(i+j-1,d.get((x*i+y*j)%10, i+j-1))
            for el in cnt.keys():
                if el not in d:
                    arr[x][y]=-1
                    break
                else:
                    arr[x][y]+=d[el]*cnt[el]
    for i in range(10):
        print(*arr[i])