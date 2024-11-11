import math
wqr = int(input())
for er in range(wqr):
    n = int(input())
    if(n==1):
        print("FastestFinger")
        continue
    elif(n==2):
        print("Ashishgup")
        continue
    elif(n%2!=0):
        print("Ashishgup")
        continue
    t = math.log(n,2)
    #print(t)
    if t == math.floor(t) :
        print("FastestFinger")
        continue
    elif(n%4==0):
        print("Ashishgup")
    else:
        cnt = 0
        i = 3
        n = n//2
        while i<int(math.sqrt(n)):
            if(n%i==0):
                cnt+=1
                break
            i+=2
        if(cnt==1):
            print("Ashishgup")
        else:
            print("FastestFinger")

    