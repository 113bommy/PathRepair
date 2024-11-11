for i in range(5):
    r=input().split(' ')
    for j in range(5):
        if r[j]=="1":
            print(abs(i-2)+abs(j-2))