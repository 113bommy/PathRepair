N=int(input())
F=[int(input()[::2],2)for _ in range(N)]
P=[list(map(int,input().split(" "))) for _ in range(N)]
print(max(sum(p[bin(i&f).count("1")]for f,p in zip(F,P))for i in r(1,1024)))