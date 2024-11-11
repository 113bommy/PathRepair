for i in range(int(input())):
    n = int(input())
    A = list(map(int,input().split(" ")));flag = 1
    for i in range(1,len(A)):
        if abs(A[i] - A[i-1]) == 1:
            flag=0
            break
    print(2) if flag==0 else print(1)