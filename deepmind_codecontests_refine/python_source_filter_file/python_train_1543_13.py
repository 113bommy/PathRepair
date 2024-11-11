N, M = map(int, input().split())
Bridge= [[int(i) for i in input().split()] for _ in range(M)]
Parent = [int(i) for i in range(N)]
Rank = [1] * N
 
def find(x):
    if x == Parent[x]: return x
    else:
        Parent[x] = y = find(Parent[x])
        return y
 
def unite(x, y, Total):
    rx, ry = find(x), find(y)
    if rx == ry: return Total
    else:
      Total -= Rank[rx] * Rank[ry]
      if rx > ry:
        Parent[rx] = ry
        Rank[ry] += Rank[rx]
      else:
        Parent[ry] = rx
        Rank[rx] += Rank[ry]
      return Total
 
Total = N * (N - 1) // 2
Ans = [str(Total)] * M
for i in reversed(range(1, M)):
    A, B = Bridge[i]
    A -= 1
    B -= 1
    Total = unite(A, B, Total)
    Ans[i - 2] = str(Total)
 
print('\n'.join(Ans))