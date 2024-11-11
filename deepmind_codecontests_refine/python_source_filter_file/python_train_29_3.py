M=1e9+7;L=8**6;d=[1]*L;d[:10]=[1]*10
for i in range(10,L):d[i]=(d[i-9]+d[i-10])%M
for s in[*open(0)][1:]:n,m=s.split();o=int(m);print(sum(d[o+int(c)]for c in n)%M)