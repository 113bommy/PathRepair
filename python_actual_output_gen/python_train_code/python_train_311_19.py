n,m=map(int,input().split())
s=[]
for i in range(n):s.append(list(map(int,input().split())))
r=s[0][1]
s.sort()
for i in range(n):
    if s[i][0]<=r:r=max(r,s[i][1])
print('YES'if m<=r else'NO')