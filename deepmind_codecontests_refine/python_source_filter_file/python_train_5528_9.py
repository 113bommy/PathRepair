s=input().strip()
s=s+s

n=len(s)
an=1
m=1
print(s)
for i in range(1,n):
    if s[i]!=s[i-1]:
        m+=1
        an = max(an, m)
    else:
        an = max(an, m)
        m=1
    #print(an)
print(min(an,n//2))