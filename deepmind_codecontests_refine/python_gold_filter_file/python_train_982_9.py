n,k,d=map(int,input().split())
if n>k**d:print(-1);exit(0)
K=1
for j in range(d):
    print(" ".join([str(i//K%k +1) for i in range(n)]))
    K*=k