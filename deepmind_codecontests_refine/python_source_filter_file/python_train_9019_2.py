from collections import Counter
n=int(input())
l=[]
for i in range(n):
    x,y=map(int,input().split())
    l.append(x)
    l.append(y)
d=Counter(l)
s1=list(d.values())
f=True
if(len(list(d.keys()))<=3):
    print('WIN')
    exit()
for p in s1:
    if(p==1):
        print('WIN')
        f=False
        break
    elif(p>=3):
        print('WIN')
        f=False
        break
if(f):
    print('FAIL')