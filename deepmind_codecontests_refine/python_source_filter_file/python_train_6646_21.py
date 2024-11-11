from collections import Counter

N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

check = [0] * (M + 1)

answer = []
for n in range(N):
  tmp = []
  for ai in A:
    for aij in ai:
      if check[aij] == 0:
        tmp.append(aij)
        break
  #print(tmp)
  counter = list(Counter(tmp).items())
  counter.sort(key = lambda x: -x[1])  
  answer.append(counter[0][1])
  check[counter[0][0]] = 1
  
print(min(answer))