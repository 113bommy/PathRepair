t = int(input())
while t:
    n = int(input())
    if n <= 3:
        print(-1)
    else:
        ans = [2, 1, 4, 3]
        for i in range(5, n+1):
            if i % 2 == 1:
                ans.append(i)
            else:
                ans.insert(0, i)
        print(*ans)
    t -= 1
