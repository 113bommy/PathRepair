import sys
sys.setrecursionlimit(1000000)

MOD = 10**9 + 7

def ex_euclid(a,b,c,d):
    if (b == 1) : return d
    x = a // b
    y = a % b
    return ex_euclid(b,y,d,(c[0]-x*d[0],c[1]-x*d[1]))
    
 
def mod_inv(a,p):
    x = ex_euclid(p,a,(1,0),(0,1))
    return x[1] % p

n,a,b,c,d = map(int,input().split())

gp = b-a+1

dp = [[-1 for j in range(n+1)] for i in range(gp)]

tb1=[0,1]
tb2=[1] #便宜上0の逆元は0にする
for i in range(2,n+1):
    tb1.append((tb1[i-1]*i) % MOD)
for i in range(1,n+1):
    tb2.append(mod_inv(tb1[i],MOD))
    

for i in range(gp):dp[i][0] = 1


def dfs(sum,k):
    summ = sum
    if(k < 0):
        if (sum != 0):return 0
        else : return 1
    if dp[k][sum] != -1: return dp[k][sum]
    kk = k+a
    temp = dfs(sum,k-1)
    temp1 = 1
    for i in range(c-1):
        if (sum < 0):break
        temp1 = (temp1 * tb1[sum] * tb2[sum-kk]*tb2[kk]) % MOD 
        sum -= kk
    for i in range(c,d+1):
        if(sum-kk < 0) : break
        temp1 = (temp1 * tb1[sum] * tb2[sum-kk]*tb2[kk]) % MOD
        sum -= kk
        temp = (temp + temp1*dfs(sum,k-1)*tb2[i]) % MOD

    dp[k][summ] = temp
    return temp
    

        
ans = dfs(n,gp-1)



print(ans)