for _ in range(int(input())):
    n = int(input())
    b = list(map(int, input().split()))
    if n == 1:
        print("YES")
        print(b[0])
        continue
    s = sum(b)
    if s % (n * (n + 1) // 2) != 0:
        print("NO")
        continue
    s = s // (n * (n + 1) // 2)
    # print(s)
    a = []
    flag = False
    for i in range(n):
        g = b[i-1] - (b[i] - s)
        if g % n == 0 and g != 0:
            a.append(g//n)
        else:
            flag = True
            print("NO")
            break
    if not flag:
        print("YES")
        print(*a)
