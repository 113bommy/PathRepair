n = list(input())
print("Yes" if min(len(set(n[:3])), len(set(n[1:])) == 1 else "No")