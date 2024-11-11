l = list(map(int, input().split()))
s, t = sum(l), 0
for i in range(len(l)):
  t += l[i]
  if(t >= s/2):
    print(i+1)
    break