import math
numproblems=int(input())
robocode=list(map(int,input().split()))
bionic=list(map(int,input().split()))
rob1=0
bionic1=0
for j in range(numproblems):
    r1=robocode[j]
    b1=bionic[j]
    if r1==1 and b1==0:
        rob1+=1
    elif r1==0 and b1==1:
        bionic1+=1
if rob1==0 and bionic1==0:
    print(-1)
elif rob1>bionic1:
    print(1)
elif rob1==bionic1:
    print(2)
elif rob1<bionic1:
    if rob1==0:
        print(-1)
    else:
        print(math.floor(bionic1/rob1)+1)
    