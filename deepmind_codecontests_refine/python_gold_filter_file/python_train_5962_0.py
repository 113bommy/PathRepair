import math
t=int(input())
def solve(m,d,w):
    k=math.gcd(w,d-1)
    w=w//k
    m=min(m,d)
    c=m//w
    print(int(c*m-w*c*(c+1)//2))
while t:
    t-=1
    m,d,w=map(int,input().split())
    solve(m,d,w)

