n, l = [int(i) for i in input().split()]

list = [int(i) for i in input().split()]

sum = 0
m = 1

for i in list:
    if i>m:
        sum = sum + i - m
    else:
        sum = sum + n + i - m
    m = i
    
print(sum)       