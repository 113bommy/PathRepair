n = int(input())

ans = [i for i in range(2, n + 1, 2)]
ans += [i for i in range(1, n + 1, 2)]
ans += [i for i in range(2, n + 1, 2)]

print(len(ans))
print(*ans)
