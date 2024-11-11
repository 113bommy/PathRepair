A,B,C,D =input()
E ="+-"

for i in E:
  for j in E:
    for k in E:
      s=A+i+B+j+C+k+D
      if eval(s)==7:
        print(s+"=7")
        exit()