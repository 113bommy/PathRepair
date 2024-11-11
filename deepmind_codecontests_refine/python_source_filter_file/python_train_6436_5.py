n,m = map(int,input().split())
l = [[int(i)for i in input().split()]for _ in [0]*n]

def  g(k):
  a = [x[0]if k&1 else -x[0])+(x[1]if k&2 else -x[1])+(x[2]if k&4 else -x[2])  for x in l]
  a.sort(reverse=True)
  return sum(a[:m])
print(max([g(i) for i range(8)]))