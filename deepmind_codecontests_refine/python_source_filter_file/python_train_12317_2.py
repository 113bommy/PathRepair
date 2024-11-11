from sys import stdin,stdout
mod=998244353
d={}
def power(x,y):
    if y<0:
        return 0
    s=str(x)+'$'+str(y)
    if d.get(s,-1)!=-1:
        return d[s]
    f=1
    y1=y
    while y:
        if y%2==1:
            f*=x
        x=x*x
        y/=2
        x%=mod
        f%=mod
    d[s]=f
    return f
ct=0
n,m=[int(i) for i in stdin.readline().split()]
a=[[i for i in stdin.readline()]for j in range(n)]
dp=[[[0,0] for i in range(m)]for j in range(n)]
c1=0
for i in range(n):
    for j in range(m):
        if a[i][j]=='o':
            dp[i][j]=[1,1]
            if i>0:
                dp[i][j][0]+=dp[i-1][j][0]
            if j>0:
                dp[i][j][1]+=dp[i][j-1][1]
            c1+=1
for i in range(n):
    for j in range(m):
        if a[i][j]=='o':
            if i>0 and a[i-1][j]=='o':
                val=dp[i][j][0]
                if val==2:
                    ct+=power(2,c1-2)
                else:
                    no=(val-1)/2
                    if val%2==0:
                        ct+=(power(2,c1-val+1)*(power(4,no)-1)*power(3,mod-2))%mod
                        ct+=power(2,c1-val)
                        ct%=mod
                    else:
                        ct+=(power(2,c1-val)*(power(4,no)-1)*power(3,mod-2))%mod
                        
            if j>0 and a[i][j-1]=='o':
                val=dp[i][j][1]
                if val==2:
                    ct+=power(2,c1-2)
                else:
                    no=(val-1)/2
                    if val%2==0:
                        ct+=(power(2,c1-val+1)*(power(4,no)-1)*power(3,mod-2))%mod
                        ct+=power(2,c1-val)
                    else:
                        ct+=(power(2,c1-val)*(power(4,no)-1)*power(3,mod-2))%mod
                    ct%=mod
            ct%=mod
stdout.write(str(ct)+'\n')
