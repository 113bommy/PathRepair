import math

n, k = input().split()
k = int(k)
cont = 0
arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

for x in range(int(n)):
    number = input()
    i = len(number)
    all = True
    for y in range (i):
        arr[int(number[y])] = 1
        
    for y in range(10):
        if k >= y:
            if arr[y] == 0:
                all = False
                break
        else:
            break
    
    if all:
        cont = cont+1
    
    for y in range(10):
        arr[y] = 0
    
print(str(cont) + " ")