n,m=map(int,input().split(" "))
s=input()
k=[s[x] for x in range(0,n)]
a=set(k)
b=[]
sum=0
t=m
print(a)
for x in a:
    b.append(k.count(x))
while m!=0:
    j=max(b)
    if j<=m:
        sum+=j**2
        m-=j
        b.remove(j)
    else:
        j=m
        sum+=j**2
        m-=j
print(sum)
