a=input()
b=input()
A,B=[],[]
dict = {'a':1,'b':2,'c':3,'d':4,'e':5,'f':6,'g':7,'h':8}
for x in a:
    A.append(x)
for x in b:
    B.append(x)
A[0],B[0]=int(dict[A[0]]),int(dict[B[0]])
A[1],B[1]=int(A[1]),int(B[1])
C=[]
while A[0]!=B[0]: 
        if A[0]<B[0]:
            if A[1]<B[1]:
                C.append('RU')
                A[0]=A[0]+1
                A[1]=A[1]+1
            elif A[1]>B[1]:
                C.append('RD')
                A[0]=A[0]+1
                A[1]=A[1]-1
            elif A[1]==B[1]:
                C.append('R')
                A[0]=A[0]+1
        elif A[0]>B[0]:
            if A[1]<B[1]:
                C.append('LU')
                A[0]=A[0]+1
                A[1]=A[1]+1
            elif A[1]>B[1]:
                C.append('LD')
                A[0]=A[0]+1
                A[1]=A[1]-1
            elif A[1]==B[1]:
                C.append('L')
                A[0]=A[0]-1
        else:
            if A[1]<B[1]:
                C.append('U')
                A[1]=A[1]+1*1
            elif A[1]>B[1]:
                C.append('D')
                A[1]=A[1]-1
while A[1]!=B[1]:
        if A[0]<B[0]:
            if A[1]<B[1]:
                C.append('RU')
                A[0]=A[0]+1
                A[1]=A[1]+1
            elif A[1]>B[1]:
                C.append('RD')
                A[0]=A[0]+1
                A[1]=A[1]-1
            elif A[1]==B[1]:
                C.append('R')
                A[0]=A[0]+1
        elif A[0]>B[0]:
            if A[1]<B[1]:
                C.append('LU')
                A[0]=A[0]+1
                A[1]=A[1]+1
            elif A[1]>B[1]:
                C.append('LD')
                A[0]=A[0]+1
                A[1]=A[1]-1
            elif A[1]==B[1]:
                C.append('L')
                A[0]=A[0]-1
        else:
            if A[1]<B[1]:
                C.append('U')
                A[1]=A[1]+1
            elif A[1]>B[1]:
                C.append('D')
                A[1]=A[1]-1
print(len(C))
while C!=[]:
    print(C[0])
    C.pop(0)