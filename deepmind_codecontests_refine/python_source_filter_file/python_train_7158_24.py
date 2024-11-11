x=list(input().strip())

patterns=["ABC","ACB","BAC","BCA","CAB","CAB"]
flag=0

if len(x)>=3:
    for i in range(2,len(x)):
        if str(x[i]+x[i-1]+x[i-2]) in patterns:
            print("Yes")
            flag=1
            break
    
    if flag==0:
        print("No")
else:
    print("No")
    