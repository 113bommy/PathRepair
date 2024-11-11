n,a,b = map(int,input().split())
towns = list(map(int,input().split()))

fatigue = 0
for i in range(n-1):
  d = towns[i+1] -towns[i]
  fatigue = max(d*a,b)
print(fatigue)