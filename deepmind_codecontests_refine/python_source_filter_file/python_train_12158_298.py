n = int(input)
ans = len(set([input() for _ in range(n)]))
print(ans)