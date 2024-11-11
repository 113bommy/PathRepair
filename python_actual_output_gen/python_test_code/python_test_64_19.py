n=int(input())
s=list(map(int,input().split()))
s.reverse()
d=s[0]
a=[]
for i in range(1,n):
    f=int(s[i])
    if f < d:
        k=str((d-f)+1)
        a.append(k)
    else:
        a.append(0)
        d=f
a.insert(0,"0")
a.reverse()
for j in a:
    print(j,end=" ")
