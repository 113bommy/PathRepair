N = int(input())
line = input()

ans = line.count('E')
tmp = ans
for i in range(1,N):
 if line[i] == 'E':
  tmp -= 1
 if line[i-1] == 'W':
  tmp += 1
 if ans>tmp:
  ans = tmp


print(ans)