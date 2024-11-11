from sys import stdin
input=lambda:stdin.readline().strip()
n=int(input())
s=input()
nd,ndd=0,0
for i in  range(0,n-1):
    if s[i]=='S' and s[i+1]=='F':
        nd+=1
    elif s[i]=='F' and s[i+1]=='S':
        ndd+=1
if nd>ndd:
    print('YES')
else:
    print('NO')
