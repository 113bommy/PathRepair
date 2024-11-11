tc=int(input())
for i in range(tc):
    s,a,b,c=map(int,input().split())
    n=s//c
    p=s//a
    q=p*b
    print(n+q)