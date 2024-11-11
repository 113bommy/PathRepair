for i in range(int(input())):
    n = int(input())
    ar = list(map(int,input()))
    c = 0
    for i in range(0,n-1):
        if ar[i] == ar[i+1]:
            c+=1
        
    print(c+1//2)
