n=int(input())
s=0
for i in range(n):
    h,m=map(int,input().split())

    s=(24*60)-((h*60)+(m))
    print