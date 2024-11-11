s=input()
for i in range(len(s)-1):
   if s[i]!=s[i-1] and s[i]!=s[i+1] and s[i-1]!=s[i+1] and s[i-1]!='.' and s[i]!='.' and s[i+1]!='.' :
       print("Yes")
       exit(0)
print("No")