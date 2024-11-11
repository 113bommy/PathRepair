n=int(input())
#print(n)
s=input()
#print(s)
c=0
if n==1 and s[0]=='0':
    c=1
for i in range(1,n):
    if s[i-1]=='1' and s[i]=='1':
        c=1
for i in range(2,n):
    if s[i]=='0' and s[i-1]=='0' and s[i-2]=='0':
        c=1
        break
if n>=2:
    if (s[1]=='0' and s[0]=='0'):
         if s[n-1]=='0' and s[n-2]=='0':        
             c=1    
if c==1:
        print("NO")
else:
        print("YES")

    