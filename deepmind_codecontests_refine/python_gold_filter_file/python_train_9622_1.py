n=input()
a=list(map(int,input().split()))
t=1
i=-1
f=0
b=[]
while (t!=0):
    if t in a[i+1:]:
        f=1
        b.append(a[i+1:].index(t)+2000+2+i)
        t=t+1
        i=a[i+1:].index(t-1)+i+1
    else:
        t=0
        break
if t==0 and f==0:
    print(t)
else:
    print(len(b))
    print(*b,sep=" ")