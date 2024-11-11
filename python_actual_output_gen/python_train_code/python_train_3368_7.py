s = input()
if len(set(s))%2 == 0 and (s.count("N") and s.count("S")) != 0 and (s.count("W") and s.count("E")) != 0:
  print("Yes")
else:
  print("No")