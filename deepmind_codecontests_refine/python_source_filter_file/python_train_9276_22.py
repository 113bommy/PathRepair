a=x=0
for s in[*open(0)][1:]:
  b={*s[1:].split()}
  a=a&b if x else b
  x=1
print(*a)