n=int(input())
for l in range(n):
    a,b=list(map(int,input().split()))
    print((b-a%b)%b)