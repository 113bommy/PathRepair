def findsmaal(a):
    for i in range(2,int(a**0.5)+1):
        if(a%i==0):
            return i
    return 0
n = int(input())
j=2
A = [0 for i in range(1,n+2)]
for i in range(2,n+1):
    if(i%2==0):
        print(1,end=" ")
    else:
        a = findsmaal(i)
        if(a==0):
            print(j,end=" ")
            A[i] = j
            j+=1
        else:
            print(A[a],end=" ")