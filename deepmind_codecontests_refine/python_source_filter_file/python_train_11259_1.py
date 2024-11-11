(n,t)=list(map(int,input('').split()))
a=[list(map(int,input('').split())) for i in range(n)]
nul=[i[0] for i in a]
inter=[i[1] for i in a]
time=[nul[i]-t if t<nul[i] else (t-nul[i])%inter[i] for i in range(n)]
s=min(time)
print (time.index(s)+1)
