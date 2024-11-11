t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a=sorted(a)
    b=sorted(a)
    print(*a)
    print(*b)