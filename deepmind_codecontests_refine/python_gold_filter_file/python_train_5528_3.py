s=input()
s=s+s+s
m=cur=1
for i in range(len(s)-1):
    if s[i]!=s[i+1]:
        cur+=1
        m=max(m,cur)
    else:
        cur=1
print(min(m,len(s)//3))
