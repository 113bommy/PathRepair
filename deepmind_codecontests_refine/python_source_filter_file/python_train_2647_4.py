t=int(input())
a=[]
b=[]
while(t!=0):
    t-=1
    n,m=map(int,input().split())
    a.append(n)
    b.append(m)
if len(set(a))>=len(set(b)):print(len(set(a)))
else:print(len(set(b)))