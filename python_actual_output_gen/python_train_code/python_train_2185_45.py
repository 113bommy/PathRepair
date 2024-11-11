h,m,H,M,k = map(int,input().split())
v = H*60+M
u = h*60+M+k
print(v-u)