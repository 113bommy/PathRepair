a,b=map(int,input().split())
arr=[1,2,3,4,5,6]
if a<b:
    count=0
    for i in range(0,len(arr),1):
        if abs(a-arr[i])<abs(b-arr[i]):
            count+=1
        else:
            break
    count1=0
    for i in range(len(arr)-1,-1,-1):
        if abs(b-arr[i])<abs(a-arr[i]):
            count1+=1
        else:
            break
    print(count,6-(count+count1),count1)
elif a>b:
    count1=0
    for i in range(len(arr)-1,-1,-1):
        if abs(a-arr[i])<abs(b-arr[i]):
            count1+=1
        else:
            break
    count=0
    for i in range(0,len(arr),1):
        if abs(b-arr[i])<abs(a-arr[i]):
            count+=1
        else:
            break
    print(count1,6-(count+count1),count)