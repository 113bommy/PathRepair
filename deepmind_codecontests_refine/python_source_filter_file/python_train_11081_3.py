s1=input()
s2=input()
s3=input()
s4=input()
x1=len(s1)-2;
x2=len(s2)-2;
x3=len(s3)-2;
x4=len(s4)-2;
a=[]
a.append((x1,1))
a.append((x2,2))
a.append((x3,3))
a.append((x4,4))
d={1:"A",2:"B",3:"C",4:"D"}
a.sort()
f1=0
f2=0
if((a[0][0]<=a[1][0]//2 and a[0][0]<=a[2][0]//2 and a[0][0]<=a[3][0]//2)):
  f1=1
elif((a[3][0]>=a[0][0]*2 and a[3][0]>=a[1][0]*2 and a[3][0]>=a[2][0]*2)):
  f2=1
if(f1==1 and f2==0):
  print(d[a[0][1]])
elif(f1==0 and f2==1):
  print(d[a[3][1]])
else:
  print("C")