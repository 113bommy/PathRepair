s=input()
print(len([True for i in range(len(s)//2) if s[i]!=s[-1-i]]))