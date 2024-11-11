results=[]
while True:
    a=input().split("\"")
    if a[0]==".":
        break
    b=input().split("\"")
    count1=0
    count2=0
    if len(a) != len(b):
        results.append(2)
    else:
        for i in range(len(a)):
            if(i%2==1):
                if len(a[i]) == len(b[i]):
                    count1+=1
                else:
                    for k,l in zip(a[i],b[i]):
                        if(k!=l):
                            count1+=1
            else:
                if len(a[i]) == len(b[i]):
                    count2+=1
                else:
                    for k,l in zip(a[i],b[i]):
                        if(k!=l):
                            count2+=1           
        if count1==0 and count2==0:
            results.append(0)
        elif count1==1 and count2==0:
            results.append(1)
        else:
            results.append(2)
for i in results:
    if i==0:
        print("IDENTICAL")
    if i==1:
        print("CLOSE")
    if i==2:
        print("DIFFERENT")
    

