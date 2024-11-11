import sys
while(True):
    items=[]
    max=0
    n, m = map(int, input().split())
    if (n == 0 & m == 0):exit()
    items = list(map(int, input().split()))
    for i in range(n):
        for j in range(n):
            sum = items[i] + items[j]
            if (i != j and sum < m and sum > max):
                max = sum
    if (max == 0):
        print("NONE")
    else:
        print(max)

