tests=int(input())
for _ in range(tests):
    n=int(input())
    arr=list(map(int,input().split()))
    t=0
    x=0
    d=[]
    for i in range(len(arr)):
        if arr[i]%2==0:
            print(1)
            print(i)

            t=1
            break
        else:
            d.append(i)
            x+=1
            if x==2:
                print(2)
                print(*d)
                break
            
    if t==1:
        continue 
    elif x==2:
        continue
    else:
        print(-1)      

