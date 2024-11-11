a = list(input())
print("Yes" if (("N" in a) ^ ("S" in a)) and (("W" in a) ^ ("E" in a)) else "No")