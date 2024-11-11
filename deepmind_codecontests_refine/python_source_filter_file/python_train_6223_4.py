s=input()
t=input()
n=len(s)
m=len(t)
r=m
for i in range(n-m+1):
    c=0
    for j in range(m):
        if s[i+j]!=t[j]:
            c+=1
    r=min(r,c)
print(c)