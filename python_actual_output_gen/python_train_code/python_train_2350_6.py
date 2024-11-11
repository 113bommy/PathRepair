check = [0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999]

for _ in range(int(input())):
    a, b = map(int, input().split())
    count = 0
    for i in range(10):
        if (b > check[i]):
            count = i
        else:
            break
        
    print(a*count)