import sys
readline=sys.stdin.readline
read=sys.stdin.read

n,c=map(int,readline().split())
#m=2*10**5
m=200
stc=[list(map(int,l.split())) for l in read().splitlines()]
cht=[[0]*(m+1) for _ in range(c)]
for e in stc:
  cht[e[2]-1][2*e[0]-1:2*e[1]]=[1 for _ in range(2*e[1]-2*e[0]+1)]
mnr=0
for i in range(1,m+1):
  mnr=max(mnr,sum(cht[ch][i] for ch in range(c)))
print(mnr)