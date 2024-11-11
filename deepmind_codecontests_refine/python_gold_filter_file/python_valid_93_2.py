numcases=int(input())
for i in range(numcases):
    data=input().split(" ")
    mex = int(data[0])
    xor= int(data[1])
    currentXor=0
    rem=(mex-1) % 4
    if(rem==1):
        currentXor=1
    elif(rem==2):
        currentXor=mex
    elif(rem==0):
        currentXor=mex-1

    if(mex==0):
        currentXor=0

    diff=currentXor ^ xor
    if(diff==0):
        print(mex)
    elif(diff == mex):
        print(mex+2)
    else:
        print(mex+1)
