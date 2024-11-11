mod=10**9+7
N,K=list(map(int,input().split()))
if (N+K)%3==0 and N*2>=K and K*2>=N:
   A=max(N,K)-min(N,K)
   low=(min(N,K)-A)//3
   all_pt=low*2+A
else:
   print(0)
   exit()
up,down=1,1
for i in range(low):
   up=up*(all_pt-i)%mod
   down=down*(i+1)%mod
base=pow(down,mod-2,mod)
print(up*base%mod)