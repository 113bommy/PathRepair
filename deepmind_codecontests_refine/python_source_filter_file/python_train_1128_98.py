N=int(input())
a=[int(i) for i in input().split()]
rates=[0]*9
for rate in a:
    rates[min(rate//400,8)]+=1
ans=0
for color in rates[:8]:
    ans+=(color!=0)
ansmax=ans+rates[8]
print(ans,ansmax)