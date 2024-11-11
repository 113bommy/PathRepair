t=int(input())
while t:
    n=int(input())
    r1=input()
    r2=input()
    lol=1
    pr=1
    i=0
    while(i<n):
        #print(i)
        if(lol==1):
            if((r1[i]=='1' or r1[i]=='2') and pr==2):
                lol=1
                print(i,"lol")
                break
            elif((r1[i]=='1' or r1[i]=='2') and pr==1):
                i+=1
                #print("lol",i)
                continue
            else:
                if(pr==1):
                    lol=2
                elif(pr==2):
                    lol=1
                    i+=1
                pr=1
        else:
            if((r2[i]=='1' or r2[i]=='2') and pr==1):
                lol=1
                break
            elif((r2[i]=='1' or r2[i]=='2') and pr==2):
                i+=1
                continue
            else:
                if(pr==1):
                    lol=2
                    i+=1
                elif(pr==2):
                    lol=1
                pr=2
     
    if(lol==2):
        print("YES")
    else:
        print("NO")
    t-=1