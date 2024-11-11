n,m=map(int,input().split())
s1=list(input())
s2=input()
i=0 
seen=0 
j=0 
if '*' not in s1:
    if s1!=s2:
        print('NO')
        exit()
while i<n and j<m:
    if s1[i]=='*':
        seen=1 
        break 
        i+=1 
    if not seen:
        if s1[i]!=s2[j]:
            print('NO')
            exit()
        else:
            i+=1 
            j+=1 
i=n-1 
seen=0 
j=m-1
while i>=0 and j>=0:
    if s1[i]=='*':
        seen=1 
        break 
    if not seen:
        if s1[i]!=s2[j]:
            print('NO')
            exit()
        else:
            i-=1 
            j-=1 
            

if '*' in s1:
    s1.remove('*')
s1=''.join(s1)
n=len(s1)
i=0 
j= 0 
c=0 
while i<n and j<m:
    if s1[i]==s2[j]:
        i+=1 
        j+=1 
        c+=1 
    else:
        j+=1 
print('YES' if c==n else 'NO')
    