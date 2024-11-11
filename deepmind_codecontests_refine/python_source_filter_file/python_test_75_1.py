
n = int(input())
arr = list(  map(int,input().split()) )


prenum = 1
while prenum < n and arr[prenum] > arr[prenum-1]:  prenum += 1

surnum = n-2
while surnum >= 0 and arr[surnum] > arr[surnum+1]: surnum -= 1


front = 0
rear = n-1

result = 0

while front<=prenum and rear >= surnum:

    if front==prenum or rear==surnum:
        result += prenum-front + rear - surnum - 1
        break

    if arr[front]<arr[rear]:
        if (rear-surnum)&1:  break
        front += 1
        result += 1

    elif arr[front]>arr[rear]:
        if (prenum-front)&1: break
        rear -= 1
        result += 1
    else:
        if (prenum-front)&1 or (rear-surnum)&1:
            break
        result += 1
        break


print(result)


if result&1:  print("Bob")
else: print("Alice")



