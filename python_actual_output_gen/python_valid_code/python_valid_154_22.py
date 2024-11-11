N=int(input())
S=[input() for _ in range(N)]
AB=sum(s.count("AB") for s in S)
EA=sum(s.endswith("A") for s in S)
SB=sum(s.startswith("B") for s in S)
EASB=sum(s.endswith("A") and s.startswith("B") for s in S)
K=min(EA,SB)-(EA==SB==EASB)
print(AB+K)