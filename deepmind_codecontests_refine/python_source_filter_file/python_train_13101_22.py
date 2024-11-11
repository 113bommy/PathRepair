n,c,k=map(int,input().split())
t=sorted([int(input()) for i in range(n)])
print(t)
a,x,y=1,1,t[0]
for i in t[1:]:
    if x==c or i>y+k:
        a+=1
        x=0
        y=i
    x+=1
print(a)