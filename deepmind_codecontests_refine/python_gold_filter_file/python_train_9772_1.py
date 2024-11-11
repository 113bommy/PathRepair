a = list(input())
print("No" if (("N" in a) ^ ("S" in a)) or (("W" in a) ^ ("E" in a)) else "Yes")