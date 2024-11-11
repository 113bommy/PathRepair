n=int(input())
for _ in range(n):
    inp=int(input())
    if (inp==1):
        print("0")
    else:
        j=inp
        count=0
        while(j!=1):
            if(j%2==0):
                j=j/2
                count+=1
            elif(j%3==0):
                j=(2*j)/3
                count+=1
            elif(j%5==0):
                j=(4*j)/5
                count+=1
            else:
                count=-1
                break
        print(count)
        