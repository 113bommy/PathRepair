n=int(input())
x=[int(q) for q in input().split()]
print(n-1)
for i in range(n-1):
    s=min(x[i+1:])
    y=x[i+1:]
    x[i],x[i+1+y.index(s)]=x[i+1+y.index(s)],x[i]
    print(i,i+y.index(s))