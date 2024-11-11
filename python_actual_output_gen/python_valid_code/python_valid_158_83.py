s=input()
a=s.index("A")
z=s[::-1].index("Z")
print(len(s[a:-z]))