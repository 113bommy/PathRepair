import math
from collections import Counter
def solve():
    n,k=map(int,input().split())
    l1=list(input())
    l1.sort()
    s1="".join(l1)
    if(k==1):
        print(s1)
        return
    d=Counter(s1)
    v=list(d.items()) 
    v.sort()
    if(1):
        c=len(d)
        if(c==1):
            kk=v[0][1]
            gg=math.ceil(kk/k)
            print(v[0][0]*gg)
            return
        elif(c==2):
            if(v[0][1]<k):
                print(v[1][0])
                return
            else:
                if(v[0][1]==k):
                    c1=1
                    c2=math.ceil(v[1][1]/k)
                else:
                    c1=v[0][1]-k+1
                    c2=v[1][1]
                print(v[0][0]*c1+v[1][0]*c2)
                return
        else:
            if(v[0][1]<k):
                print(s1[k-1])
                return
            else:
                if(v[0][1]==k):
                    c1=1
                else:
                    c1=v[0][1]-k+1
                d1=v[0][0]*c1
                for i in range(1,c):
                    d1+=v[i][0]*v[i][1]
            print(d1)
            return
for _ in range(int(input())):
    solve()