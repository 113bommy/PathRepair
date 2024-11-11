t = int(input())
for _ in range(t):
    blank = input()
    n, m = map(int, input().split())
    dct = {i:[] for i in range(1, n + 1)}
    for times in range(m):
      start, end = map(int, input().split())
      dct[start].append(end)
    dis = {1:0}
    stack = [1]
    iterate = [1]
    so = 1
    decoy = 0
    while so < n:
      decoy = stack.pop(0)
      for adj in dct[decoy]:
        if adj in dis:
          continue
        else:
          so += 1
          dis[adj] = dis[decoy] + 1
          iterate.append(adj)
          stack.append(adj)
    ans = [dis[i] for i in range(1, n + 1)]
    for node in iterate[::-1]:
      minn = dis[node]
      for adj in dct[node]:
        if dis[adj] <= dis[node]:
          minn = min(minn, dis[adj])
        else:
          minn = min(ans[adj - 1], minn)
      ans[node - 1] = minn
    print(*ans)