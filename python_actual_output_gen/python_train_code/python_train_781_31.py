n1, n2, n3 = list(map(int, input().split()))
print(min(n1 + n2 + n3, n1 * 2 + n2 * 2, n1 * 2 + n3 * 2, n2 * 2 + n2 * 2))
