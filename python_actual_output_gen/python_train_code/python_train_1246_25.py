n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
m1=max(b)
t=0
c=[]
for i in range(n):
    if b[i]==m1:
        t=i
        break
    else:
        c.append(b[i])
for j in range(t+1,n):
    c.append(b[i])
m2=max(c)
if sum(a)>m1+m2:
    print("NO")
else:
    print("YES")
    

