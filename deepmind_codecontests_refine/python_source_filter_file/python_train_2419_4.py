x=int(input())
for a in range(0,x):
    y=input().split()
    if int(y[1])%int(y[0])==0:
        print(0)
    else:
        print(int(y[1])-(int(y[0])%int(y[1])))
