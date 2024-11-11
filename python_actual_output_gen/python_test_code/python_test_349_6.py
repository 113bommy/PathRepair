n,t,k,d=map(int,input().split())
u=0--n//k
u-=d//t+(d%t==0)
print('YNEOS'[u<=0::2])