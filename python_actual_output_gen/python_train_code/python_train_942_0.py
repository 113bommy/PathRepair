N=int(input())
inp=list(map(int, input().strip().split(' ')))
Xsort=sorted(inp)
med = int(N/2)
for i in range(N):
  if Xsort[med-1] > inp[i]:
    print(Xsort[med])
  else:
    print(Xsort[med-1])