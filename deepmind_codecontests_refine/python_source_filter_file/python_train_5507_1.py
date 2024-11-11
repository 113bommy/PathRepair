import sys
r=sys.stdin.readline
for e in iter(r,'0'):
 R=[[]for _ in[0]*-~int(e)]
 for _ in[0]*int(r()):
  a,b=map(int,r().split())
  R[a]+=[b];R[b]+=[a]
 for m in R[1][:]:R[1]+=R[m]
 print(len({*R[1]}-{1}))
