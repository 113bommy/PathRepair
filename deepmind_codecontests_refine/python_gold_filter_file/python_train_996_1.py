flag=1
a,b=map(int,input().split())
c,d=map(int,input().split())
for i in range(1,1000):
    if flag==1:
        for j in range(1,1000+1):
            if b+a*i-a-d-c*j+c==0:
                print(b+(i-1)*a)
                flag=0
                break
    else:
        break



if flag==1:
    print("-1")




