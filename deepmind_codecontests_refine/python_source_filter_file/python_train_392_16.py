N = int(input())
l = [int(input()) for i in range(N)]
l_ = sorted(l)
for Ai in l:
  if l_[0] == Ai:
    print(l_[1])
  else:
    print(l_[0])