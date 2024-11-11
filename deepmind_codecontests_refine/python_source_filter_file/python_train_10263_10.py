n=int(input())
x=[int(x) for x in input().split()]
c=0
if n<=2:
    print(0)
else:
    g=max(x)
    l=min(x)
    for i in range(n):
        if l<x[i]<g:
            c=c+1
print(c)            
