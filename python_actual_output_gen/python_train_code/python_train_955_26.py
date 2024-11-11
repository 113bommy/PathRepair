test_cases = [(input(), list(map(int, input().split())))[1] for _ in range(int(input()))]

for case in test_cases:
  flag = True
  for i in range(len(case) - 1):
    if abs(case[i] - case[i + 1]) > 1:
      print('YES')
      print(i, i + 1)
      flag = False
      break

  if flag:
    print('NO')