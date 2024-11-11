def f(k):
    if k==1:return d
    if k==0:return 0
    if k in m:return m[k]
    s=min(k*d,f(k//2)+a+k%2*d,f(--k//2)+a+-k%2*d,f(k//3)+b+k%3*d,f(--k//3)+b+-k%3*d,f(k//5)+c+k%5*d,f(--k//5)+c+-k%5*d)
    m[k]=s
    return s
for _ in range(int(input())):
    m={}
    n,a,b,c,d=map(int,input().split())
    print(f(n))