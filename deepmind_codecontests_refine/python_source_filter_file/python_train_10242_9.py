

y=[1,1,1,1,1,1,1,1,1]
x=[1,1,1,1,1,1,1,1,1]
x[0],x[1],x[2]=map(int,input().split())
x[3],x[4],x[5]=map(int,input().split())
x[6],x[7],x[8]=map(int,input().split())
for i in range(0,9):
    if (i == 0):
        if((int(x[i])%2)!=0):
            y[i]=int(not y[i])
            y[i+1]=int(not y[i+1])
            y[i+3]=int(not y[i+3])
        elif((int(x[i]) %2)==0):
            continue
    elif(i==1):
        if ((int(x[i]) % 2) !=0):
            y[i] = int(not y[i])
            y[i + 1] = int(not y[i + 1])
            y[i - 1] = int(not y[i - 1])
            y[i + 3] = int(not y[i + 3])
        elif ((int(x[i])  % 2) == 0):
            continue
    elif (i == 2):
        if ((int(x[i])  % 2) != 0):
            y[i] = int(not y[i])
            y[i - 1] = int(not y[i - 1])
            y[i + 3] = int(not y[i + 3])
        elif ((int(x[i])  % 2) == 0):
            continue
    elif (i == 3):
        if ((int(x[i]) % 2) !=0):
            y[i] = int(not y[i])
            y[i + 1] = int(not y[i + 1])
            y[i + 3] = int(not y[i + 3])
            y[i - 3] = int(not y[i - 3])
        elif ((int(x[i])  % 2) == 0):
            continue
    elif (i == 4):
        if ((int(x[i]) % 2) !=0):
            y[i] = int(not y[i])
            y[i + 1] = int(not y[i + 1])
            y[i - 1] = int(not y[i - 1])
            y[i + 3] = int(not y[i + 3])
            y[i - 3] = int(not y[i - 3])
        elif ((int(x[i]) % 2) == 0):
            continue
    elif (i == 5):
        if ((int(x[i])  % 2) !=0):
            y[i] = int(not y[i])
            y[i - 1] = int(not y[i - 1])
            y[i + 3] = int(not y[i + 3])
            y[i - 3] = int(not y[i - 3])
        elif ((int(x[i]) % 2) == 0):
            continue
    elif (i == 6):
        if ((int(x[i])  % 2) !=0):
            y[i] = int(not y[i])
            y[i + 1] = int(not y[i + 1])
            y[i - 3] = int(not y[i - 3])
        elif ((int(x[i])  % 2) == 0):
            continue
    elif (i == 7):
        if ((int(x[i]) % 2) !=0):
            y[i] = int(not y[i])
            y[i + 1] = int(not y[i + 1])
            y[i - 1] = int(not y[i - 1])
            y[i - 3] = int(not y[i - 3])
        elif ((int(x[i]) % 2) == 0):
            continue
    elif (i == 8):
        if ((int(x[i])  % 2) !=0):
            y[i] = int(not y[i])
            y[i - 1] = int(not y[i - 1])
            y[i - 3] = int(not y[i - 3])
        elif ((int(x[i])  % 2) == 0):
            continue
for i in range(0,3):
    print(y[i], end='')
print('\n')
for i in range(3,6):
    print(y[i], end='')
print('\n')
for i in range(6,9):
    print(y[i], end='')

