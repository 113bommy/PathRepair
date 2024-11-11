n = int(input())

RGB, RBG, GRB, GBR, BRG, BGR = n, n, n, n, n, n

s = input()

for i in range(n):
    if i%3==0:
        if s[i]=="R":
            RGB -= 1
            RBG -= 1
        elif s[i]=="G":
            GRB -= 1
            GBR -= 1
        else:
            BRG -= 1
            BGR -= 1
    elif i%3==1:
        if s[i]=="R":
            GRB -= 1
            BRG -= 1
        elif s[i]=="G":
            RGB -= 1
            BGR -= 1
        else:
            RGB -= 1
            GBR -= 1
    else:
        if s[i]=="R":
            GBR -= 1
            BGR -= 1
        elif s[i]=="G":
            RGB -= 1
            BRG -= 1
        else:
            RGB -= 1
            GRB -= 1

m = min(RBG, RGB, BRG, BGR, GRB, GBR)

print(m)

if m == RBG:
  print("RBG"*(n//3)+"RBG"[:n%3])
elif m == RGB:
  print("RGB"*(n//3)+"RGB"[:n%3])
elif m == BRG:
  print("BRG"*(n//3)+"BRG"[:n%3])
elif m == BGR:
  print("BGR"*(n//3)+"BGR"[:n%3])
elif m == GRB:
  print("GRB"*(n//3)+"GRB"[:n%3])
elif m == GBR:
  print("GBR"*(n//3)+"GBR"[:n%3])
