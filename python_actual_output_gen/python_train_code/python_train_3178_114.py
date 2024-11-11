k, s = int(input()), input()
print(s[::k] + "..." if len(s) > k else s)