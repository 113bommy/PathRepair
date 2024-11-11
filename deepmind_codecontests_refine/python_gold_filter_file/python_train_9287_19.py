import math
def check(n,d):
    return (n*n + 2*n +1 >=4*d)
t=int(input())
while t:
    t-=1
    n,d=map(int,input().split())
    if check(n,d):
        print("YES")
    else:
        print("NO")