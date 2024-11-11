t=int(input())
for q in range(t):
    a,b=map(int,input().split())
    print((b-a%b)%b)
