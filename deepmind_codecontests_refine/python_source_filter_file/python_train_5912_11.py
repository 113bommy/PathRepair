data = input().split(" ")
N, K, C = int(data[0]), int(data[1]), int(data[2])
S = input()

point = 0
work_start = [0] * (K + 1)
for i in range(1, K + 1):
  point = S.find("o", point, N)
  work_start[i] = point + 1
  point += C

point = N
work_end = [0] * (K + 1)
for i in range(K, 0, -1):
  point = S.rfind("o", 0, point)
  work_end[i] = point + 1
  point -= C

for i in range(1, K + 1):
  if work_start[i] == work_end[i]:
    print(work_start[i])