n = int(input())
B = list(map(int, input().split()))
tot = B[0]+B[-1]
for i in range(n-2):
  tot += min(B[i], B[i+1])
print(tot)