n = input()

arr = n.split("1")

flag = True 

if(arr[0] == '4'):
    flag = False 

else:
    for num in arr:
        if(num == '' or num == '4' or num == '44'):
            continue 

        else:
            flag = False 
            break 

if(flag):
    print("YES")

else:
    print("NO")       