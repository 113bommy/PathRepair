m = int(input())
for j in range(m):
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    used = [0] * (n + 1)
    t = 1
    b.append(a[0])
    f = True
    used[a[0]] = 1
    for k in range(1, n):
        if a[k] == a[k - 1]:
            while used[t] == 1:
                t += 1                    
            if t < a[k - 1]:
                b.append(t)
                used[t] = 1
                t += 1
            else:
                f = False
                break
        elif a[k] > a[k - 1]:
            b.append(a[k])
            used[t] = 1
        else:
            f = False
            break
    if f:
        print(*b)
    else:
        print(-1)
            
