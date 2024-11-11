n = int(input())
lst = [i*(i+1)//2 for i in range(1, 1 + int((2*n)**0.5))]
high = len(lst)-1
low = 0
flag = False

if n//2 in lst:
    flag = True
else:
    while low < high:
        if lst[low] + lst[high] == n:
            flag = True
            break
        elif lst[low] + lst[high] > n:
            high -= 1
        else:
            low += 1

print('YES' if flag else 'NO')
