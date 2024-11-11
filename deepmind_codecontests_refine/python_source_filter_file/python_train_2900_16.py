i,o,t,j,l,s,z = map(int, input().split())
k = o*2
p = (i//2 + j//2 + l//2)*4
q = 0
if i*j*k:
  q = ((i-1)//2 + (j-1)//2 + (l-1)//2)*4 + 6
print(k + max(p, q)) 