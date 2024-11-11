Vladik,Valera=map(int,input().split())
i=1
while True:
    if Vladik-i<0:
        print("Vladik")
        exit()
    elif Valera-i-1:
        print("Valera")
        exit()
    Vladik=Vladik-i
    Valera=Valera-i-1
    i+=2