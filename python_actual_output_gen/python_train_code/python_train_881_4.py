t=int(input())
for i in range(t):
    a,b,n,S=map(int,input().split())
    d = min(S/n,a)
    d = S-d*n

    if (d <= b):
        print("YES")
    else:
        print("NO")
