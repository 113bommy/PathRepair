def main():
  [n,m,q] = list(map(int, input().split(" ")))
  s = input()
  t = input()
  queries = []
  for _ in range(q):
    queries.append(list(map(int, input().split(" "))))
  #toss the obvious
  if len(s) < len(t):
    for _ in range(q):
      print(0)
  else:
    ref = [0]
    for i in range(len(s)-len(t)+1):
      j = i
      #print(j)
      if s[j:j+len(t)] == t:
        ref.append(ref[-1]+1)
      else:
        ref.append(ref[-1])
    print(ref)
    for x in queries:
      if x[1]-len(t)+1 < x[0]-1:
        print(0)
      else:
        print(ref[x[1]-len(t)+1]-ref[x[0]-1])

main()