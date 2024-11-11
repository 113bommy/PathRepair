n=int(input())
a=list(map(int,input().split()))
o,e=[],[]
for i in range(n):
    if a[i]%2==0:
        e.append(i)
    else:
        o.append(i)
if len(o)==1:
    print(o[0]+1)
else:
    print(e[0]+1)