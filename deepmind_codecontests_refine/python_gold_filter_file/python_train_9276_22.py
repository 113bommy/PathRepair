a=x=0
for s in[*open(0)][1:]:
  b={*s.split()[1:]}
  a=a&b if x else b
  x=1
print(*a)