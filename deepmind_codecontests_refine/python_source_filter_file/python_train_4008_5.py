n,w = input().split()

n = int(n)
w = int(w)

k = input().split()
k = [int(x) for x in k]
x = float(w) / float(3 * n)
#print(x)
k.sort()

if k[0] < x:
  x = k[0]
  
if k[n] < 2 * x:
  x = float(k[n]/2)
  
ans = float(3*n*x)

#print(ans)
print("%g" % ans)