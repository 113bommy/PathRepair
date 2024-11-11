for s in[*open(0)][1:]:
  n,m=map(int,s.split())
  a=['W'+'B'*(m-1)]+['B'*m]*(n-1)
  print(*a,sep='\n')