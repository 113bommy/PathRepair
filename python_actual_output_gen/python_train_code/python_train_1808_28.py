n = int(input())
arr = input()
arr1 = [0]*10
for i in range(n):
    if(arr[i] == 'L'):
        for j in range(0,9):
            if(arr1[j] == 0):
                arr1[j] = 1
                break
    elif(arr[i] == 'R'):
        for j in range(9,0,-1):
            if(arr1[j] == 0):
                arr1[j] = 1
                break
    else:
        x = int(arr[i])
        arr1[x] = 0
for i in range(0,10):
    print(arr1[i],end="")
    