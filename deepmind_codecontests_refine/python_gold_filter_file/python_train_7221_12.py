for i in range(5):
    a=input().split()
    for j in range(5):
        if a[j]== '1':
            print(abs(i-2)+abs(j-2))
