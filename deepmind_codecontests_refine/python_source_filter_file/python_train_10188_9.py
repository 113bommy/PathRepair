n=int(input())
c=list(map(int, input().split()))
a=list(range(n,n**2+1,n))
b=list(range(n**2,0,-n))
for i in range(n):
    b[i]=b[i]+c[i]
    
for i in a:
    print(i,end=' ')
print()
for i in b:
    print(i,end=' ')
print()