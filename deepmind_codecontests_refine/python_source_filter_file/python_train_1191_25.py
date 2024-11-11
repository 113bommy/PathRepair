n=input()
arr=list(map(int,input().split()))
ka=[]
kr=sorted(arr)
if (kr==arr):
    print ("yes")
    print (1,1)
else:
    for i in range(len(arr)-1):
        if arr[i]-arr[i+1]<0:
            ka.append(-1)
        else:
            ka.append(1)
    #print (ka)
    k=ka.count(1)
    cnt=0
    stindex=ka.index(1)
    lastindex=len(ka) - 1 - ka[::-1].index(1)

    #print (stindex)
    #print (lastindex)
    #print (k)


    if (stindex+k-1)!=lastindex:
        print ("No")
    else:
        arr[stindex:lastindex+2] = arr[stindex:lastindex+2][::-1]
        #print (arr)
        ks=sorted(arr)
        if (ks==arr):
            #print (arr)
            print ("yes")
            print (stindex+1,lastindex+2)

        else:
            print ("no")
    #1 2 3 4 8 7 6 5 11 12 13 14