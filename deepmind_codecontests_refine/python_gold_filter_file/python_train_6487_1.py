n,m,k=map(eval,input().split())
r = 0
if k>n or k == 1:
    r = m**n
elif k == n:
    r = m**((n+1)//2)
elif k%2 == 0:
    r = m
else:
    r = m*m 

print (int(r%(10**9+7)))
