n = int(input())
g = 0
t=0
for i in range(n):
    s,a,b,c=map(int,input().split())
    g=s//(a*c)
    s-=g*a
    t=g*(a+b)+s//c
    print(t)
    


