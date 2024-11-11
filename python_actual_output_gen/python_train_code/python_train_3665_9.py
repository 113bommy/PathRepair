a = int(input())
z =a//7
x = a%7
if x ==0:print(z*2,z*2)
elif x<3:print(z*2,(z*2)+x)
elif x>5:print(z*2,(z*2)+1)
else:print(z*2,(z*2)+2)
