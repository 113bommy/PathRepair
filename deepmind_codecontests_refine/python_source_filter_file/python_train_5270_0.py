k=0
c='aeiou'
s=input()
i=2
while i<len(s):
    if (s[i]!=s[i-1] or s[i]!=s[i-2] or s[i-1]!=s[i-2]) and s[i] not in c and s[i-1] not in c and s[i-2] not in c:
        s=s[:i]+" "+s[i:]
        i+=1
    i+=1
print(s)