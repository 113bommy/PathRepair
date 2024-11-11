import heapq
n, k, x = map(int, input().split())
chores = list(map(int, input().split()))
chores.sort()
chores = chores[:n - k]
sec = heapq.nlargest(k, chores)
tot = k * x + sum(chores)
print(tot)
