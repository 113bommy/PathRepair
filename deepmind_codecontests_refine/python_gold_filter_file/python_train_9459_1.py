N, *A = map(int, open(0).read().split())
ans = 0
B = sorted(A)
dic = {B[i]:i for i in range(N)}
for i,n in enumerate(A):
  if i%2!=dic[n]%2:
    ans += 1
print(ans//2)