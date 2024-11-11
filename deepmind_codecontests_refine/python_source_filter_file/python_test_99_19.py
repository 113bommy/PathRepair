T = int(input())
for t in range(T):
    x, n = map(int, input().split())
    if n==0:
        ans = x
    elif x%2==0:
        if n%4==1:
            ans = x-n
        elif n%4==2:
            ans = x+1
        elif n%4==3:
            ans = x+n+1
        elif n%4==0:
            ans = 0
    else:
        if n%4==1:
            ans = x+n
        elif n%4==2:
            ans = x-1
        elif n%4==3:
            ans = x-n-1
        elif n%4==0:
            ans = x
    print(ans)
            
