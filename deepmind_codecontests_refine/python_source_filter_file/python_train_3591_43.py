n, m =map(int , input().split())
t1=n-m
t2=n-t1-1
if t1>=t2 and m+1 <= n:
    print(m+1)
elif t1<t2 and m-1 >= 1:
    print(m-1)
elif n == m:
    print(n)

