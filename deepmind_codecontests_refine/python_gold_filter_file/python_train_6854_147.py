n = input()
print("No" if len(n) < 4 else "Yes" if n[:4] == "YAKI" else "No")