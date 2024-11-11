s=input()
print("No" if "L" in s[1::2] or "R" in s[::2] else "Yes")