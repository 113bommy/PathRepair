a = list(input())
print("Yes" if ~(("N" in a) ^ ("S" in a)) or ~(("W" in a) ^ ("E" in a)) else "No")