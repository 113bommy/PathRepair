count = int(input ())

for item in range(count):
    readline = input ().split() 
    n = int(readline[0])
    k = int(readline[1])   
    if (n % k == 0):
        result = n 
    elif (n % k > k// 2):
        result = k + k // 2 
    else:
        result = n
    print(result)