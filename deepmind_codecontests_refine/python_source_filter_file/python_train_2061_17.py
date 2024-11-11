S = input()
print("NO" if "L" in S[::2] or "R" in S[1::2] else "YES")