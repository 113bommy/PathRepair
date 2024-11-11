N = int(input())
S = input()
sride = 1
count = 0
max_num = 0
for i in range(N-1):
  for j in range(N-sride):
    if S[j] == S[j+sride]:
      count += 1
      max_num = max(max_num, count)
    else:
      count = 0
    if count == sride:
      max_num = max(max_nuzm, count)
      break
  sride += 1
  count = 0
print(max_num)
