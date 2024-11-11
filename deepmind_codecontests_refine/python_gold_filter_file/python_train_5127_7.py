t = int(input())
def check(x,y):
    p=0
    if x%2==0:
        print(x+2*y)
    else:
        for i in range(3,n+1,2):
            if x%i==0:
                p = i
                break
        print(x+p+2*(y-1))
for _ in range(t):
    n,m = map(int,input().split())
    check(n,m)