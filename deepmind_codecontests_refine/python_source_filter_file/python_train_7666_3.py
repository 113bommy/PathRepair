s=list(input())
alp='abcdefghijklmnopqrstuvwxyz'
j=0
for i in range(len(s)):
    if s[i]>=alp[j]:
         s[i]=alp[j]
         j+=1
    if j==26:
         print(''.join(s))
         break
else:
    print(-1)