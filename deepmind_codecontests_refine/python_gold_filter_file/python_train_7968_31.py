n = int(input())
if n==1 or n==2: print(-1)
elif n%2==1: print((n*n-1)//2, (n*n+1)//2)
else: print((n//2*n//2-1), (n//2*n//2+1))