s = int(input())
n = 1000000000
x = (n-s%n)%n
y = (s+x)//n
print(*[1,n,y,x,0,0])