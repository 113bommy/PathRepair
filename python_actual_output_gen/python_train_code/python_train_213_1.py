n=list(map(int,  input().split(' ')))
ai= list(map(int, input().split(' ')))
bi= list(map(int, input().split(' ')))
flag=True
for i in range(n[1]-2):
    if(ai[i]!= bi[i]):
        flag=False
        print("LIE")
        break
if(flag):
    for i in range(n[2]-n[1]):
        if(ai[n[1]+i]!=bi[n[1]+i]):
            flag=False
            print("LIE")
            break
if (flag==True):
    print('TRUTH')