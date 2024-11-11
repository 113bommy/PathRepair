def get_point(info):
  info.reverse()
  acc = 0
  NORMAL, SPARE, STRIKE, DOUBLE = 0, 1, 2, 3
  flag = NORMAL
  game_num = 0
  while info:
    if game_num != 9:
      down_num1 = info.pop()
      if down_num1 != 10:
        down_num2 = info.pop()
        if flag == SPARE:
          acc += down_num1 * 2 + down_num2
        elif flag == STRIKE:
          acc += down_num1 * 2 + down_num2 * 2
        elif flag == DOUBLE:
          acc += down_num1 * 3 + down_num2 * 2
        else:
          acc += down_num1 + down_num2
        
        if down_num1 + down_num2 == 10:
          flag = SPARE
        else:
          flag = NORMAL
      
      else:
        if flag in (SPARE, STRIKE):
          acc += down_num1 * 2
        elif flag == DOUBLE:
          acc += down_num1 * 3
        else:
          acc += down_num1
        if flag in (STRIKE, DOUBLE):
          flag = DOUBLE
        else:
          flag = STRIKE
      game_num += 1

    else:
      down_num1, down_num2 = info.pop(), info.pop()
      if flag == SPARE:
        acc += down_num1 * 2 + down_num2
      elif flag == STRIKE:
        acc += down_num1 * 2 + down_num2 * 2
      elif flag == DOUBLE:
        acc += down_num1 * 3 + down_num2 * 2
      else:
        acc += down_num1 + down_num2
      if info:
        acc += info.pop()
  
  return acc

while True:
  m = int(input())
  if m == 0:
    break
  score = [list(map(int, input().split())) for _ in range(m)]
  score_mp = [(info[0], get_point(info[1:])) for info in score]
  score_mp.sort()
  score_mp.sort(key=lambda x:-x[1])
  for pair in score_mp:
    print(*pair)
