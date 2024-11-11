t=int(input())
for i in range(t):
    a,b,d,c=map(int,input().split())
    print(max(a+b,d+c))