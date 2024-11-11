a, b = map(int, input().split())

if(a == b):
    print('infinity')
elif(a < b):
    print(0)
else:
    dif = a - b
    i = 2
    result = 1
    while i*i <= a:
        if(dif % i == 0):
            if(i > b):
                result += 1
            if dif//i > b and i*i != a:
                result += 1
        i += 1
    print(result)