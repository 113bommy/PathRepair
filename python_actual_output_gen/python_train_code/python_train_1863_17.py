s, k = input(), int(input())
print(k - len(set(s)) if len(s) >= k else "impossible")