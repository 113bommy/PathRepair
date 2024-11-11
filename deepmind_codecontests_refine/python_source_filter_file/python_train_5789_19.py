y=[]
check=1
x1=input()
x2=input()
x3=input()
x4=input()
y1=[x1.split()]
y2=[x2.split()]
y3=[x3.split()]
y4=[x4.split()]
y=y1+y2+y3+y4+y

if y[0][3]=='1':
    if  y[0][0]=='1' or y[0][1]=='1' or y[0][2]=='1':
        check=0
    elif y[1][0]=='1' or y[2][1]=='1' or y[3][2]== '1':
        check=0
elif y[1][3]=='1':
    if y[1][0]=='1' or y[1][1]=='1' or y[1][2]=='1':
        check=0
    elif y[2][0]=='1' or y[3][1]=='1' or y[0][2]=='1':
        check=0
elif y[2][3]=='1':
    if y[2][0]=='1' or y[2][1]=='1' or y[2][2]=='1':
        check=0
    elif y[3][0]=='1' or y[0][1]=='1' or y[1][2]== '1':
        check=0
elif y[3][3]=='1':
    if y[3][0]=='1' or y[3][1]=='1' or y[3][2]=='1':
        check=0
    elif y[0][0]=='1' or y[1][1]=='1' or y[2][2]=='1':
        check=0
if check==0:
    print('YES')
else:
    print("NO")
  
