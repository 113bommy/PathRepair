A,B,C,D,E,F=map(int,input().split())
satoumizu=1
satou=0
for a in range(31):
  for b in range(16):
    for c in range(F-100*A*a-100*B*b):
      for d in range(F-100*A*a-100*B*b-C*c):
        if a==0 and b==0 and c==0 and d==0:
          continue
        if E*(A*a+B*b)>=C*c+D*d and 100*(A*a+B*b)+C*c+D*d<=F:
          if (C*c+D*d)/(100*(A*a+B*b)+C*c+D*d)>satou/satoumizu:
            satoumizu=100*(A*a+B*b)+C*c+D*d
            satou=C*c+D*d
print(satoumizu,satou)