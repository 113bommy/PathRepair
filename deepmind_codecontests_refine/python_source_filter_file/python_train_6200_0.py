
input()
arr = list(map(int, input().split()))

def sumK(arr, k):
  m = {} # a + b = k
  total = 0

  for number in arr:
    if number in m:
      total += m[number]
      m[number] += 1
    else:
      compl = k - number
      m[compl] = m.get(compl, 0) + 1

  return total
 
k = 1
ans = 0
while k <= 2*10**9:
  ans += sumK(arr, k)
  k *= 2

print(ans)
