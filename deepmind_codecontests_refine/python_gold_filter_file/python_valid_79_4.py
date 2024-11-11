t = int(input())
for _ in range(t):
  k = int(input())
  n = input()
  if ("1" in n) or ("4" in n) or ("6" in n) or ("8" in n) or ("9" in n) :
    print(1)
    for a in ["1", "4", "6", "8", "9"]:
      if a in n:
        print(int(a))
        break
  
  elif n.count("2") >= 2 or n.count("3") >= 2 or n.count("5") >= 2 or n.count("7") >= 2:
    print(2)
    for a in ["2", "3", "5", "7"]:
      if n.count(a) >= 2:
        print(10*int(a)+int(a))
        break

  else:
    if k == 4:
      for i in range(4):
        if n[i] == "2":
          break
      for j in range(4):
        if n[j] == "5":
          break
      if i < j:
        print(2)
        print(25)
      else:
        print(2)
        print(52)

    if k == 3:
      if "2" in n:
        for i in range(3):
          if n[i] =="2":
            break
        if i > 0:
          print(2)
          print(int(n[0])*10+2)
        else:
          if "5" in n:
            print(2)
            print(25)
          else:
            print(2)
            print(27)

      else:
        for i in range(3):
          if n[i] =="5":
            break
        if i > 0:
          print(2)
          print(int(n[0])*10+5)
        else:
          print(2)
          print(57)

    if k == 2:
      print(2)
      print(n)