t = int(input())
 
answer = []
 
for i in range(t):
    n = int(input())
    a, b = input().split()
    a, b = int(a), int(b)
 
    length = 0
 
    for i in range(n - 1):
        x, y = input().split()
        x, y = int(x), int(y)
 
        if length == 0:
            if (a <= x <= b)and(a <= y <= b):
                a, b = x, y
            elif a <= x <= b:
                a = x
            elif a <= y <= b:
                b = y
            elif y < a:
                a, b = y, a
                length = -1
            else:
                a, b = b, x
                length = -1
 
        else:
            if y < a:
                a = y
            elif x > b:
                b = x
 
    if length == 0:
        a = b
 
    answer.append(b - a)
 
for i in answer:
    print(i)
            
