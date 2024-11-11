n, a, x, b, y = map(int, input().split())

first = True
second = True
while first and second:   
    a += 1
    if a == n+1:
        a = 1
    
    b -= 1
    if b == 0:
        b = n

    # print(a, b)
    if a == b:
        print("YES")
        break

    if a == x:
        first = False
    
    if b == y:
        second = False

else:
    # print(a, x, b ,y)
    print("NO")