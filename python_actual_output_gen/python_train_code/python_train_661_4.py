s=input()
b=''
l=len(s)
flag=0
for i in range(l):
    if s[i]!='a':
        b=b+s[i]
l1=len(b)
if l1%2==0:
    t=l1//2
    d=b[:t]
    c=s[l-t:]
    for j in range(t):
        if c[j]!=d[j]and c[j]=='a':
            flag=1
            break
else:
    flag=1
if flag==0:
    print(s[:l-t])
else:
    print(':(')
    
