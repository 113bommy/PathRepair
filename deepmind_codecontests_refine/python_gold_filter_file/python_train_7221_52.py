for i in range(5) :
    L=input().split()
    for j in range(5) :
        if L[j]=="1" :
            print(abs(i-2)+abs(j-2))