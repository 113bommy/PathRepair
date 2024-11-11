N = int(input())
ans = 'No'
for i in range(100+1):
  if i % 4 == 0 and (N - i) % 7 == 0:
    ans = 'Yes'

print(ans)