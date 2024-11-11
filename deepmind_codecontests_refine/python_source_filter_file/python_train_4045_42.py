S = list(input())

print("Yes" if len(S) == len(set(S)) else "no")