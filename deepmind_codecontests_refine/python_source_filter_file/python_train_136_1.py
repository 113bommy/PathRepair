a, b, c =list(map(int,input().split()))
left = 0 
right = 1000*b
while right > left + 1: 
    middle = (left + right) // 2
    x = middle * b
    for i in range(c):
        x=x-a+b
    if x < 0: 
        left = middle 
    else: 
        right = middle
print(right)
