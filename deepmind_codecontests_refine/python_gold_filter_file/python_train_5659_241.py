s=input()
s=s.replace('WUB',' ')
s=list(s)
n=len(s)
i=0
while i<n:
    if s[i]==' ':
        del s[i]
    else:
        break
m=len(s)
while i<m-1:
    if s[i]==' ' and s[i+1]==' ':
        del s[i+1]
        m=m-1
    else:
        i=i+1
s=(''.join(s))
print(s)