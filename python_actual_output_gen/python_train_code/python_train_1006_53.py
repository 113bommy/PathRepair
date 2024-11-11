a = input()
for i in range(0, int(a)):
  line = input()
  if len(line)<=4:
    print(line)
  else :
    line2 = line[1:len(line)-1]
    print(line[0]+""+str(len(line2))+""+line[len(line)-1])