n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    b=(9*(a-1)+b)
    print(b)
