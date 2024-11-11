def CountSteps(x1,y1,x2,y2):
  return max(abs(x2-x1),abs(y2-y1))

length=int(input())
x,y=map(int,input().split())
white=CountSteps(1,1,x,y)
black=CountSteps(x,y,length,length)

#print(white,black)

if white<=black:
  print("White")
else:
  print("Black")