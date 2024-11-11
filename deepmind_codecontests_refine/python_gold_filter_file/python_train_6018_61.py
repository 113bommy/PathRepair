s=input()
n=len(s)
v=[[0]*13 for i in range(n+1)]
v[0][0]=1
m=10**9+7
for i in range(n):
    for j in range(13):
        for k in range(10):
            x=(10*j+k)%13
            v[i+1][x]=(v[i+1][x]+(1 if s[i]=='?' or s[i]==str(k) else 0)*v[i][j])%m
print(v[n][5])
