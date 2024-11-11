n=int(input())
A=set()
B={'purple':'Power',
   'green':'Time',
   'blue':'Space',
   'orange':'Soul',
   'red':'Realyty',
   'yellow':'Mind'}
C={'Power',
   'Time',
   'Space',
   'Soul',
   'Realyty',
   'Mind'}
for i in range(n):
    A.add(input())
D=set()
for i in A:
    D.add(B[i])
E=C-D
print(6-n)
for i in E:
    print(i)
