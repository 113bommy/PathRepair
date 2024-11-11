cnt=0
time_list=[]
tc = eval(input())
#print(tc)
while cnt<tc:
    #print("CNT:", cnt, sep=',')
    n_k = input()
    l=[]
    l=n_k.split(' ')
    n=int(l[0])
    k=int(l[1])

    tap_pos = input()
    tap_pos_list = tap_pos.split(' ')

    #print(tap_pos_list[0])
    arr=[]
    c=0
    for i in range(0,n):
        if c<k and i==(int(tap_pos_list[c])-1):
            arr.append(1)
            c+=1
        else:
            arr.append(0)

    #print(arr)

    time=1
    flag=False
    while flag==False:
        if time==1:
            for i in arr:
                if i!=1:
                    flag=False
                    break;
                flag=True
                #print('y')
            
            if flag==True:
                time+=1
                break;
            time+=1
            #print('n')
        else:
            print('time : ', time, sep='')
            c=0
            for i in range(len(arr)):
                if c<k and i==(int(tap_pos_list[c])-1):
                    if i==0:
                        arr[i+(time-1)]=1
                    elif i==(len(arr)-1):
                        arr[i-(time-1)]=1
                    else:
                        if (i-(time-1))>=0:
                            arr[i-(time-1)]=1
                        if (i+(time-1))<=(len(arr)-1):
                            arr[i+(time-1)]=1
                    c+=1
            for i in arr:
                if i!=1:
                    flag=False;
                    break;
                flag=True
            time+=1
    time_list.append(time-1)
    #print(';-------------')
    #for i in time_list:
     #   print(i)
    cnt+=1

for i in time_list:
    print(i)
