s=input()
print(len(s)-s[::-1].index("z")+s.index("A"))