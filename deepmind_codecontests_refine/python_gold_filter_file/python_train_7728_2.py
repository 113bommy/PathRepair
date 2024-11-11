mod = 998244353 
power = [1]*200005
for i in range(1,200005) :
    power[i]=(10*power[i-1])%mod
n = int(input())
for i in range (1,n) :
    res = 2*10*9*power[n-i-1]
    res+= (n-i-1)*10*9*9*power[n-i-2]
    print(res%mod,end=' ')
print(10)