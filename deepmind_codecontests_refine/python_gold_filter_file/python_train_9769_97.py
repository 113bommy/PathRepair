N = input()
print("Yes" if len(set(N[:3])) == 1 or len(set(N[1:])) == 1 else "No")