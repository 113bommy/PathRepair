def bellman_ford(V, E, s, std):
  dist = [float('inf') for _ in range(V)]
  dist[s] = 0
  for i in range(V):
    for s, t, d in std:
      s -=1
      t -= 1
      d = -d
      if dist[t] > dist[s] + d:
        dist[t] = dist[s] + d 
        if i == V-1 and t+1 == V:
          return -1 
  return dist

def main():
  N, M = map(int, input().split())
  abc = [list(map(int, input().split())) for _ in range(M)]
  dist = bellman_ford(N, M, 0, abc)
  if dist == -1:
    print('inf')
    exit()
  else:
    print(-dist[N-1])

if __name__ == "__main__":
  main()