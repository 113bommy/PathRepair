n, x = map(int, input().split())
m = 2*n-1

if n==2 and x==2:
    print("Yes")
    print("1\n2\n3")
elif x==1 or x==m:
    print("No")
else:
    if x < n:
        print("Yes")
        base = [str(i) for i in [m, x, 1, m-1]]
        ans = [str(i) for i in range(2, n) if i!=x] + base + [str(i) for i in range(n, m-1)]
        print("\n".join(ans))
    else:
        print("Yes")
        base = [str(i) for i in [1, x, m, 2]]
        ans = [str(i) for i in range(2, n)] + base + [str(i) for i in range(n, m-1) if i!=x]
        print("\n".join(ans))
