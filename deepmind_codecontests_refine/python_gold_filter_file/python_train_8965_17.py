for i in range(int(input())):
    A=[int(x) for x in input().split()]
    if(A[0]==A[2] and A[1]==A[3]):
        print(str(A[0])+' '+str(A[3]))
    elif(A[0]==A[2]):
        print(str(A[1])+' '+str(A[3]))
    elif(A[1]==A[3]):
        print(str(A[0])+' '+str(A[2]))
    else:
        print(str(A[0])+' '+str(A[2]))
              
