def dig(num):
    return int(str(num))

a, b = map(int, input().split())

mult = 1

if b - a >= 4:
    print(0)
else:
    for i in range(b-a):
        mult *= dig(b-i)
        
    print(str(mult)[-1])
