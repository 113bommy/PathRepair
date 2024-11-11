n,a,b=map(int,input('').split())
a=list(map(int,input('').split()))
b=list(map(int,input('').split()))
for i in range(n):print(('1' if (i in a) else '2'),end=" ")
