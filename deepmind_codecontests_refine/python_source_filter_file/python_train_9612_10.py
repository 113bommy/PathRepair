import math
n=int(input())
power=[3]
for i in range(1,int(math.log(n,2))+1):
    power.append(power[-1]**2%1000000007)
s=bin(n)[2:]
s=s[::-1]
exp=1
for i in range(len(s)):
    if s[i]=='1':
        exp=(exp*power[i])%1000000007
print((exp+(-1)**int(str(n)[-1])*3)//4)
