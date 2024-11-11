A, B, C, D, E, F = map(int, input().split())
M = 0
Sans = 0
Concmax = 0

for i in range(F//100//A+1):
  WA = i*100*A
  for k in range((F-WA)//100//B+1):
    WB = k*100*B
    W = WA+WB
    if W <= F:
      for j in range((F-W)//C+1):
        SC = j*C
        for l in range((F-W-C)//D+1):
          SD = l*D
          S = SC+SD
          if 0 < W+S <= F and S <= W*E/100:
            Conc = S/(S+W)
            if Conc > Concmax:
              Concmax= Conc
              Sans = S
              M = S+W
#              print(WA,WB,SC,SD,Conc)
print(M,Sans)