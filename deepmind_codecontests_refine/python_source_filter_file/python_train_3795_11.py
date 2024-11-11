n = int(input())
c = "*" *n
x = 1
mid = False
for i in range(n):
    if i == (n-1)/2:
        mid = True
    a = c[:int((n-x)/2)+1]
    b = "D"*x
    print(a+b+a)
    if mid == True:
        x -= 2
    else:
        x += 2