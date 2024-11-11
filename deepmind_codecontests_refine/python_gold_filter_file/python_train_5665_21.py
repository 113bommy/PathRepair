n = int(input())
array = []
upper=  0
lower =0 
for i in range(n):
    array.append(list(map(int,input().split())))
    upper+=array[i][0]
    lower+=array[i][1]
if(upper%2==0 and lower%2==0):
    print(0)
elif(upper%2==0 and lower%2!=0):
    print(-1)
elif(upper%2!=0 and lower%2==0):
    print(-1)
else:
    flag = 0
    for  i in range(n):
        if(array[i][1]%2!=0 and array[i][0]%2==0):
            flag =1
            break
        if(array[i][1]%2==0 and array[i][0]%2!=0):
            flag = 1
            break
    if(flag==1):
        print(1)
    else:
        print(-1)
