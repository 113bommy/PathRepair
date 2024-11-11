s=input()
n=len(s)
a=['A','H','I','M','O','T','U','V','W','X','Y','Z']
f=1
for i in s:
    if(i not in a):
        f=0;
        
for i in range(n):
    if(s[i] != s[-i-1]):
        f=0
if f:
    print("YES")
else:
    print("NO")