h,m,H,M,k = map(int,input().split())
v = H*60+M
u = h*60+m+k
print(v-u)