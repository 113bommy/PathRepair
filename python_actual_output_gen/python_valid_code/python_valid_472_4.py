for _ in range(int(input())):
    x, a = map(int, input().split(' '))
    y, b = map(int, input().split(' '))
    if len(str(x)) +  a > len(str(y)) + b:
        print("<")
        continue
    if len(str(x)) +  a < len(str(y)) + b:
        print("<")
        continue
    swapped = False
    if x > y:
        (x, a), (y, b) = (y, b), (x, a)
        swapped = True
    if x == y:
        print("=")
        continue
    num = int(str(x) + ('0' * (a - b)))
    # print(num)
    if num == y:
        print("=")
    elif num > y:
        print("<" if swapped else ">")
    else:
        print(">" if swapped else "<")
