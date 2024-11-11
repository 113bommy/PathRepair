n, l = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
ans = False
for bega in range(n):
    for begb in range(n):
        ch = True
        for i in range(n):
            x, y = 0, 0
            if bega + i + 1 == n:
                x = l - a[n - 1] + a[0] - 1
            else:
                x = a[(bega + i + 1) % n] - a[(bega + i) % n]
            if begb + i + 1 == n:
                y = l - b[n - 1] + b[0] - 1 
            else:
                y = b[(begb + i + 1) % n] - b[(begb + i) % n]
            if x != y:
                ch = False
                break
        if ch:
            ans = True
            break
    if ans:
        break
if ans:
    print("YES")
else:
    print("NO")
