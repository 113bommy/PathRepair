for i in range(5):
    x=input().split()
    for j in range(5):
        if x[j]=='1':
            print(abs(i-2)+abs(j-2))
