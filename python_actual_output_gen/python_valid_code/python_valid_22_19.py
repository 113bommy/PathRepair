a=int(input())

b=list(map(int,input().split()))

ch=0
bi=0
ba=0

for i in range(len(b)):
    if(i<3):
        if(i==0):
            ch+=b[i]
        if(i==1):
            bi+=b[i]
        if(i==2):
            ba+=b[i]
    else:
        if(i%3==0):
            ch+=b[i]
        if(i%3==1):
            bi+=b[i]
        if(i%3==2):
            ba+=b[i]

if(ch>bi and ch>ba):
    print('chest')

elif(ch<bi and bi>ba):
    print('bisceps')

elif(ba>ch and ba>bi):
    print('back')