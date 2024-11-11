n = int(input())
s = str(input())
c=0
q=0
p=(n-11)//2
for i in range(0,n):
    if s[i]=='8':
        c=c+1
        if c==p:
            q=i+1
if p>=q-p and c>p:
    print('YES')
else:
    print('NO')
