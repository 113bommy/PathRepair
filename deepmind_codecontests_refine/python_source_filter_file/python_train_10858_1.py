
answers = []

def solve(l, r, arr, req, n, k):
  if l == r:
    answers.append(k-1)
    return
  
  if l == 1 and r == n:
    answers.append(req[r-1])
  elif l == 1:
    answers.append(req[r-1] + k - arr[r-1] - (arr[r]-arr[r-1]-1))
  elif r == n:
    answers.append(req[r-1] - req[l-2] + arr[l-1] - 1 - (arr[l-1]-arr[l-2]-1))
  else:
    answers.append(req[r-1] - req[l-2] + arr[l-1] - 1 - (arr[l-1]-arr[l-2]-1) + k - arr[r-1] - (arr[r]-arr[r-1]-1))




n, q, k = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

smaller = []
larger = []
mid = []

req = []

if n > 1:
  req.append(arr[1]-2)

for i in range(1, n-1):
  left = arr[i-1]+1
  right = arr[i+1]-1
  req.append(right-left)

if n > 1:
  req.append(k-1-arr[-2])

length = len(req)
print(req)
for i in range(1, length):
  req[i] += req[i-1]

print(req)

while q:
  l, r = [int(x) for x in input().split()]
  solve(l, r, arr, req, n, k)
  q -= 1

for ans in answers:
  print(ans)