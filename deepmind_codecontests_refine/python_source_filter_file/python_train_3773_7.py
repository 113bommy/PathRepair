t = int(input())

for i in range(t):
    n = int(input())
    numbers = list(map(int, input().split()))
    numbers.sort()
    middle = (n // 2) - 1

    counter = 0
    arr = []
    flag = True
    
    while counter < n:
        if flag:
            arr.append(numbers[middle - counter])
            middle -= counter
            counter += 1
            flag = False
            

        else:
            arr.append(numbers[middle + counter])
            middle += counter
            counter += 1
            flag = True


    print(*arr)
