t=int(input())
b=[]
if 0<=t and t<=180:
    for i in range(t):
        a=int(input())
        for i in range(3,1000):   
            if a==(i-2)/i*180:
                ot="YES"
                break
            else:
                ot="NO"
        b.append(ot)       
    for i in range(t):
        print(b[i])
else:
    print("Nevernoe znach")