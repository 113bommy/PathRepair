for i in range(5):
    m=input().split()
    for j in range(5):
        if m[j]=='1':
            print(abs(i-2)+abs(j-2))