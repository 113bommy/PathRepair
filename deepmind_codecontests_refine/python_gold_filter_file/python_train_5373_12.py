s, k = input(), int(input())
print((max(k - len(set(s)), 0), "impossible")[len(s) < k])