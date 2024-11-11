x1,y1,x2,y2=map(int,input().split())
x,y=map(int,input().split())
if x1==x2 and y1==y2:print("YES")
elif x2==x1 and abs(y2-y1)%y==0:
   move_y=abs(y2-y1)//y
   if move_y%2==0:print("YES")
   else:print("NO")
elif y2==y1 and abs(x2-x1)%x==0:
   move_x=abs(x2-x1)//x
   if move_x%2==0:print("YES")
   else:print("NO")
elif abs(x2-x1)%x==0  and abs(y2-y1)%y==0:
 move_x=abs(x2-x1)//x;move_y=abs(y2-y1)//y
# print(move_x,move_y)
 if abs(move_x-move_y)%2==0:print("YES")
 else:print("NO")
else:print("NO")
