N,M=map(int,input().split())
n=['0']*N
a=0
for i in range(M):
    s,c=map(str,input().split())
    if n[int(s)-1]!='0' and n[int(s)-1]!=c:
        a=1
    if s=='1' and c=='0' and N!=1:
        a=1
    n[int(s)-1]=c
if n[0]=='0' and N!=1:
    n[0]='1'
if a==0:
    print(''.join(n))
else:
    print(-1)