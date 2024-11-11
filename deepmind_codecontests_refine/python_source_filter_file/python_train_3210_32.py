a, b, k = map(int, input().split())
print(*[i for i in range(a, b+1) if (i < a+k) or (i > b-k)], sep = '\n')