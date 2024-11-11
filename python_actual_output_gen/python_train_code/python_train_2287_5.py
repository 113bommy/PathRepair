n=int(input())
a=[0]*n
for i in range(n):
    a[i]=input()
m=a[0][0]
s=a[0][1]
for i in range(n):
    if a[i][i]!=a[i][-i-1] or (a[i][i]==a[i][-i-1] and a[i][i]!=m):
        ans=False
        break
    elif a[i].count(s)+a[i].count(m)!=n and ((a[i].count(m)==2 and i!=n//2+1) or (a[i].count(m)==1 and i==n//2+1)):
        ans=False
        break
    ans=True
if ans and m!=s:
    print('YES')
else:
    print('NO')
    
        
        
