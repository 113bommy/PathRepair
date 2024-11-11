s=input()
c="CODEFORCES"
a="NO"
for i in range(len(s)):
    for j in range(i,len(s)):
        if s[:i]+s[j:]==c:a="YES"
print(a)