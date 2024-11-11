
t = int(input())
while t!=0:

    n = int(input())
    s=0
    i = 0
    list1 = []
    count=0
    while s<n:
        p = pow(2,i)
        if len(list1)==0:
            list1.append(1)
            count+=1
            s=1
        else:
            list1[-1]=  list1[-1]+p
            s+= (list1[-1]*(list1[-1]+1)/2)

            if s<=n:
                count+=1
            else:
                break
        i+=1

    print(count)




    t-=1