s, k = input(), int(input())
print((k - len(set(s)), "impossible")[len(s) < k])
