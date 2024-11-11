n = int(input())
arr = list(map(int, input().split()))
arr.sort()
frq = {}
csnt = {}

frq[arr[0]] = 1
for i in range(1,len(arr)):
  if arr[i] in frq:
      frq[arr[i]] += 1
  else:
      frq[arr[i]] = 1
      
  if arr[i] - arr[i-1] in csnt:
      csnt[arr[i] - arr[i-1]] += 1
  elif arr[i] - arr[i-1] > 0:
      csnt[arr[i] - arr[i-1]] = 1

print("YES" if len(frq) < 4 and len(csnt) < 2 else "NO")