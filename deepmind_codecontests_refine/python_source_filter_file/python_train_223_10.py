t=int(input())
for _ in range(t):
    a,b,n=map(int,input().split())
    if n==0:
        print(a)
    if n==1:
        print(b)
    else:
        print(a^b)