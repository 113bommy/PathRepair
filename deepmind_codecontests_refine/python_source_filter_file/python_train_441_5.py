for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    c = list(map(int,input().split()))
    ans = [a[0]]
    for i in range(1,n-1):
        if ans[-1] != a[i]:
            ans.append(a[i])
        elif ans[-1] != b[i]:
            ans.append(b[i])
    if a[n-1] != ans[-1] and a[n-1] != ans[0]:
        ans.append(a[i])
    elif b[n-1] != ans[-1] and b[n-1] != ans[0]:
        ans.append(b[n-1])
    else:
        ans.append(c[n-1])
    print(*ans)
