s = int(input())

m = 10**9
x = (m-s%m)%m
y = (s+x)//m
print(0,0,m,1,x,y)