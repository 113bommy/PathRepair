import math
n = int(input())
s = (-1+math.sqrt(1+8*n))/2
if (int(s)!=s):
    print("No")
else:
    print("Yes")
    s = int(s)
    print(s+1)
    A = []
    w = 1
    for i in range(s+1):
        print(s, end=" ")
        for j in range(len(A)):
            print (A[j][i-j-1], end=" ")
        A.append([])
        for j in range(s-len(A)+1):
            print(w, end=" ")
            A[i].append(w)
            w+=1
        print()