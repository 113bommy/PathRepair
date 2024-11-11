for _ in range(int(input())):
     s = input()
     t = 0
     if s[-5:] == 'lala.':
          t += 1
     if s[5:] == 'miao.':
          t += 2
     if t == 2:
          print("Rainbow's")
     elif t == 1:
          print("Freda's")
     else:
          print("OMG>.< I don't know!")