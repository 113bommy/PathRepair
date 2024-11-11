def pal(s):
    l=len(s)
    if l%2==0:k=l//2
    else:k=l//2+1
    #print(s[:l//2])
    #print(''.join(reversed(s[k:])))
    if s[:l//2]==''.join(reversed(s[k:])):return True
    else:return False
s=input()
i=len(s)-1
while s[i]=='0':
    i-=1
j=0
while s[j]=='0':
    j+=1
if pal(s[j:i+1]):
    print('YES')
else:
    print('NO')
