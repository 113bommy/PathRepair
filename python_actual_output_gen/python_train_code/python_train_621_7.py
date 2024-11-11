N,K=map(int,input().split())
S=input()
e=(S[0]=='L')+(S[-1]=='R')
i=S.count("RL")
c=max(i-K,0)*2+max(e-max(K-i,0),0)

print(N-c)