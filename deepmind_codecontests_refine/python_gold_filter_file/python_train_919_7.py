from itertools import accumulate
n,k = map(int,input().split())
a = list(map(int,input().split()))
suma = 0
for i in range(k,n):
  suma += max(0,a[i])
acca = [0]+list(accumulate(a))
ans = [max(suma,suma+acca[k])]
for i in range(1,n-k+1):
  suma += max(0,a[i-1])
  suma -= max(0,a[i+k-1])
  ans.append(max(suma,suma+acca[i+k]-acca[i]))
print(max(ans))