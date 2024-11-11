s = input()
a = {s[i:]+s[:i] for i in range(len(s))}
print(len(a))