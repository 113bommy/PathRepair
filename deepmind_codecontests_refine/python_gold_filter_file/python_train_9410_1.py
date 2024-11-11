s=input()
a=list(s.split('@'))
ans=''
for i in range(1,len(a)-1):
    if len(a[i])<=1:print('No solution');exit()
if len(a[0])==0 or len(a[len(a)-1])==0 or '@' not in s:print('No solution');exit()
j=0
for i in range(len(s)):
    if s[i]=='@':
        ans+=s[j:i+2]+','
        j=i+2
ans=ans[:len(ans)-1]+s[j:]
print(ans)