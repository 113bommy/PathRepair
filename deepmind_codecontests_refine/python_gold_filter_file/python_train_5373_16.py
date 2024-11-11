s, k = input(), int(input())
print(max(0, k - len(set(s))) if len(s) >= k else "impossible")