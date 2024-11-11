while 1:
 H, W = map(int, input().split())
 if H == 0 and W == 0:
  break
 print("#"*W)
 line = '#' + ('.' * (W - 2)) + '#'
 for i in range(0, H - 2):
  print(line)
 print("#"*W,'\n')