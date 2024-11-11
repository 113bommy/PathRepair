t = int(input())
for j in range(t):
    n,x = map(int, input().split())
    ali = list(map(int, input().split()))
    bli = list(map(int, input().split()))
    q = sorted(ali)
    e = sorted(bli)
    w = sorted(ali, reverse=True)
    r = sorted(bli, reverse=True)
    f=0
    for i in range(n):
        if(q[0]+r[0] > x):
            f=1
            break
    if(f==0):
        print("Yes")
    else:
        print("No")
    if(j != t-1):
        a = input()