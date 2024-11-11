n = int(input())
List = [int(input()) for _ in range(n)]
c, s = 1, List[0]
while s!=2 and c>=n:
  c+=1
  s = List[s-1]
print(-1 if c>=n else c)