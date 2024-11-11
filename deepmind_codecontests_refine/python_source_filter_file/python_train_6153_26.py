A=input().split()
B=input()
Answ=[]
for i in range(int(B)):
    Koor=input().split()
    if (int(Koor[1])<int(Koor[0])+int(A[1])) and (int(Koor[1])>int(Koor[0])-int(A[1])) and (int(Koor[1])<-1*int(Koor[0])+int(A[1])) and (int(Koor[1])<-1*int(Koor[0])+2*int(A[0])-int(A[1])):
        Answ.append('YES')
    else:
        Answ.append('NO')
        
for i in range(int(B)):
    print(Answ[i])