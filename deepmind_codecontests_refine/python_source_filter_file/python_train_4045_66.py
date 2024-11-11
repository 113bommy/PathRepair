S = input().strip()
print("Yes" if len(S) == len(set(list(S))) else "No")
