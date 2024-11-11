S = input()
print("Yes" if sum([2==S.count(ch) for ch in S]) else "No")
