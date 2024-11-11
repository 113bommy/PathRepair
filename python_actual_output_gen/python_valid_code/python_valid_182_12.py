a,b=map(int,input().split())
x=[int(x) for x in input().split()]
s=0
for i in range(a-1):
    d=b-x[i]
    if(d>x[i+1]):
        p=x[i+1]
        x[i+1]=d
        s=s+d-p
print(s)
print(x)