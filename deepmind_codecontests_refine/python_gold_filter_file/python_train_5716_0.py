def solve():
  n, k = map(int,input().split())
  group_num = 10
  
  book_map = [[] for i in range(group_num)]
  acc_map = [[0] for i in range(group_num)]

  for i in range(n):
    c,g = map(int,input().split())
    book_map[g - 1].append(c)

  for i in range(group_num):
    book_map[i].sort(reverse=True)
    acc = 0
    for j in range(len(book_map[i])):
      book_map[i][j] += j * 2
      acc += book_map[i][j]
      acc_map[i].append(acc)
#  print(acc_map)  
  dp = [[0] * (k + 1) for i in range(group_num + 1)]
  for y in range(1,k + 1):
    for x in range(1,group_num + 1):
      for z in range(min(y + 1, len(acc_map[x - 1]))):
        dp[x][y] = max(dp[x][y], dp[x - 1][y - z] + acc_map[x - 1][z])
  
  print(dp[group_num][k])
solve()

