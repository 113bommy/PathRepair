y,b=map(int,input().split())
ye,g,bl=map(int,input().split())
yellow=2*ye+1*g
blue=1*g+3*bl
if yellow<=y and blue>b:
     print(abs(blue-b))
elif yellow>y and blue<=b:
     print(abs(yellow-y))
elif yellow>y and blue>b:
     print(abs((yellow+blue)-(y+b)))
else:
     print(0)

