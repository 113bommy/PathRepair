while True:
  WH = input().split()
  if WH[0] == '0': break
  for i in range(int(WH[1])):
    print('#'*int(WH[0]))
  print()