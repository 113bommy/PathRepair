a, b, k = map(int, input().split())
print([x for x in range(1, min(a,b)+1) if a%x == b%x == 0][k-1])
