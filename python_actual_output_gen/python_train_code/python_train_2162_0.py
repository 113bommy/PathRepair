t=int(input())
def solve(n):
    if n==1:return 0
    q=int(n**0.5)
    if q**2==n:return q*2
    else:
        if q*(q+1)<n:return q*2
        else:return q*2-1
for i in ' '*t:print(solve(int(input())))