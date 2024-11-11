N,M=map(int,input().split());mod=998244353;B=[]
for i in range(N):
    s=int(input().replace(" ",""),2)
    for b in B:s=min(s,s^b)
    if s!=0:B.append(s)
print((pow(2,N+M-1,mod)*(1-pow(2,mod-1-len(B),mod)))%mod)
