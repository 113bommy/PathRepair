n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    b=b*(a-1)
    print(b)
