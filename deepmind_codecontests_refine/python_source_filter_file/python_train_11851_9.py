N = int(input())
if N == 3:
    print(*[2, 5, 63])
elif N == 4:
    print(*[2, 5, 20, 63])
elif N == 5:
    print(*[2, 5, 20, 30, 63])
else:
    ans = []
    k = 0
    for i in range(2, 30000):
        if i % 2 == 0 or i % 3 == 0:
            ans.append(i)
            k += 1
            if k == N:
                break

    if sum(ans) % 6 == 0:
        print(*ans)
    elif sum(ans) % 6 == 2:
        for j in range(N):
            if ans[j] == 8:
                ans.pop(j)
                break
        ans.append(30000)
        print(*ans)
    elif sum(ans) % 6 == 3:
        for j in range(N):
            if ans[j] == 9:
                ans.pop(j)
                break
        ans.append(30000)
        print(*ans)
    else:
        for j in range(N):
            if ans[j] == 9:
                ans.pop(j)
                break
        ans.append(29998)
        print(*ans)
