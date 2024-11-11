s=input()
l=len(s)
print("Yes" if s[:l//2][::-1]+s[l//2]+s[(l+1)//2:][::-1]==s==s[::-1] else "No")