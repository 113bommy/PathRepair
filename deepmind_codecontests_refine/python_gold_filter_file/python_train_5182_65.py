# -*- coding: utf-8 -*-

N,K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))

answer = max(C)
for i in range(N):
  pos = P[i] - 1
  score = C[pos]
  score_list = [score]
  step = 1
  while pos!=i and step<K:
    pos = P[pos] - 1
    score += C[pos]
    score_list.append(score)
    step += 1
  score_max = max(score_list)
  if score_list[-1]>0 and step<K:
    loop = K//step
    amari = K%step
    for j in range(step):
      if j<amari:
        score_max = max(score_max, score_list[-1]*loop+score_list[j])
      else:
        score_max = max(score_max, score_list[-1]*(loop-1)+score_list[j])
  answer = max(answer,score_max)

print(answer)