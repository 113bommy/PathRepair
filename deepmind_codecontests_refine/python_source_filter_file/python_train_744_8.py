q = int(input())
for j in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1 or n == 2 or n == 3:
        print("YES")
    else:
        run = 1
        if a[0] == (a[n-1] + 1) % n:
            for i in range(n-1):
                if not(a[i+1] % n == (a[i]+1) % n):
                    run = 0
                    break
        elif a[0] == (a[n-1] - 1) %n:
            for i in range(n-1):
                if not(a[i+1] % n == (a[i]-1) % n):
                    run = 0
                    break
        else:
            run = 0
        if run == 1:
            print("YES")
        else:
            print("NO")