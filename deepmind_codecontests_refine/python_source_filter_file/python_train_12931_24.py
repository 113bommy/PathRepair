n, m=map(int,input().split())
a=list(input().split())
b=list(input().split())
t=int(input())
for i in range(t):
    x=int(input())
    print(a[(x%n)]+b[(x%m)])
