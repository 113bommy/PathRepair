T = int(input())
x = 0
a = [[0]*4]*T
while(x!=T):
    a[x] = [int(i) for i in input().split(" ")]
    x+=1
x = 0
while(x!=T):
    if(a[x][1] ==0 and a[x][2] ==0 and a[x][3]==0):
        if (a[x][0]%2==1):
            print("Ya Tidak Tidak Tidak")
        else:
            print("Tidak Tidak Tidak Ya")
    elif(a[x][0] ==0 and a[x][2] ==0 and a[x][3]==0):
        if (a[x][1]%2==1):
            print("Tidak Ya Tidak Tidak")
        else:
            print("Tidak Tidak Ya Tidak")
    elif(a[x][0] ==0 and a[x][1] ==0 and a[x][3]==0):
        print("Tidak Tidak Ya Tidak")
    elif(a[x][0] ==0 and a[x][1] ==0 and a[x][2]==0):
        print("Tidak Tidak Tidak Ya")
    elif(a[x][0] ==0 and a[x][3]==0):
        if (a[x][1]%2==1):
            print("Tidak Ya Tidak Tidak")
        else:
            print("Tidak Tidak Ya Tidak")

    elif ((a[x][0]+a[x][1])%2 == 1):
        if(a[x][1] == 0 and a[x][2]== 0):
            print("Ya Tidak Tidak Tidak")
        else:
            print("Ya Ya Tidak Tidak")
    
    else:
        if(a[x][1] ==0 and a[x][2] ==0):
            print("Tidak Tidak Tidak Ya")
        else:
            print("Tidak Tidak Ya Ya")
    x+=1