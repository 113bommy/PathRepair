from sys import stdin

A=int(stdin.readline())
B=stdin.readline()
C=list()
sum=0

for k in range(0,A):
    sum+=int(B[k])
    C.append(sum)

Q=0
U=0

if sum==0:
    print('YES')
    U=1

if U==0:
 for k in range(0,len(C)):
    if C[k]==0:
        continue

    if sum%C[k]==0:
       SUM=0
       q=0
       for t in range(k+1,len(C)):
           SUM+=int(B[t])

           if SUM==C[k]:
               SUM=0
               q=1
           elif SUM>C[k]:

               break

           if t==len(C)-1:

               if q==1:
                  print('YES')

                  Q=1
                  break

    if Q==1:
        break

if Q==0:
    print('NO')