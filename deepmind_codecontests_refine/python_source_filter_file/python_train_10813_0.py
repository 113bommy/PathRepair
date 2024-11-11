def comp(lst1, lst2):
  for v1, v2 in zip(lst1, lst2):
    if v1 < v2:
      return False
    if v1 > v2:
      return True

  return False

while True:
  try:
    plst = list(map(int, input().split()))
    
    horse = [4, 1, 4, 1, 2, 1, 2, 1]
    min_num = 100000
    min_horse = horse[:]
    
    for _ in range(8):
      #乗車不能人数
      num = sum([max(0, plst[j] - horse[j]) for j in range(8)])
      
      #人数が最小値と等しく、並びの数値が小さければ更新
      if num == min_num and min_horse > horse:
        min_hose = horse[:]
      
      #人数が最小値より小さければ更新
      elif num < min_num:
        min_num = num
        min_horse = horse[:]
      
      #馬を回転
      horse.append(horse.pop(0))

    print(" ".join(map(str, min_horse)))

  except EOFError:
    break
