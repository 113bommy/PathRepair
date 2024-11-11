n,k,d=map(int,input().split())
if n>k**d:print(-1);exit(0)
r=1
for j in range(d):
    print(" ".join([str(i//r%k +1) for i in range(n)]));r*=k