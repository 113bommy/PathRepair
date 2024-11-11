a, b = map(int, input().split())
a1, a2, a3 = map(int, input().split())
ans1 = a1 * 2 + a2
ans2 = a2 + 3 * a3
print(min(ans1 - a, 0) + min(ans2 - b, 0))