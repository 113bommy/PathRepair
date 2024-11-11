for i in range(5):
    s=input().split()
    for j in range(5):
        if s[j]=="1":
            print(abs(j-2)+abs(i-2))