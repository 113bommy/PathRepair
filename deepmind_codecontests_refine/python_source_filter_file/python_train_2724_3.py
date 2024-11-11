n1,n2,k1,k2=[int(x) for x in input().split()]
dp=[[0 for _ in range(n2+1)] for _ in range(n1+1)]
dp[0][0]=1
for i in range(1,min(k1+1,n1+1)):
    dp[i][0]=1
for i in range(1,min(k2+1,n2+1)):
    dp[0][i]=1
for p in range(1,n1+1):
    for q in range(1,n2+1):
        for i in range(1,min(k1+1,p+1)):
            for j in range(1,min(k2+1,q+1)):
                #print(p,q,i,j)
                #if p==1 and q==2: print("BRO",p-i,q-j,i,j)
                #if n1==p and n2==q: print("LOL",p-i,q-j)
                if p==i and q==j:
                    dp[p][q]+=2*dp[p-i][q-j]
                else: dp[p][q]+=dp[p-i][q-j]
                dp[i][j]%=100000000
#print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in dp]))
print(dp[n1][n2])
