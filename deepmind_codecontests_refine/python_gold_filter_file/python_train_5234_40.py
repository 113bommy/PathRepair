tt=int(input())
for _ in range(tt):
    a,b=map(int,input().split())
    print((b-(a%b))%b)