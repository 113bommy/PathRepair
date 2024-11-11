n = input()
l = n.replace("hi","a")

print("No" if len(set(l)) != 1 else "Yes")