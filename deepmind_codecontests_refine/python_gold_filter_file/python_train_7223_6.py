import sys
for line in sys.stdin:
    line_number = int(line)
    for line in range(line_number):
        s = input()
        Freda, Rainbow = False, False
        if s[-5:] == 'lala.':
            Freda = True
        if s[:5] == 'miao.':
            Rainbow = True
        if Freda == True and Rainbow == True or Freda == False and Rainbow == False:
            print("OMG>.< I don't know!")
        elif Freda:
            print("Freda's")
        elif Rainbow:
            print("Rainbow's")
        else:
            pass

