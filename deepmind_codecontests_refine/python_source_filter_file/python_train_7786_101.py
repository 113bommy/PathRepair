s = int(input())
n = 1000000000
x = (n-s%n)%n
y = (s+x)//n
print(*[1,n,x,y,0,0])