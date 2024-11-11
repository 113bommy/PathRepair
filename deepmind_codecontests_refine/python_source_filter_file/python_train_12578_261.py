a,b=map(int,input().split())
c=[a-b,b-a,a*b]
c.sort()
print(c[2])