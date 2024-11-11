n=int(input())
a=list(map(int,input().split()))
print(2*n-1)
if abs(max(a))>=abs(min(a)):
     b=a.index(max(a))
    for i in range(n):
        print(b+1,i)
    for j in range(n-1):
        print(j+1,j+2)
    
else:
    b=a.index(min(a))
    for i in range(n):
        print(b+1,i+1)
    for j in range(n-1,0,-1):
        print(j+1,j)