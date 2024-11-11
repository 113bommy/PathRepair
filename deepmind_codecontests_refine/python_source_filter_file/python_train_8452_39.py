p = int(input())

for t in range(p):
    entrada = input().split(" ")
    n = int(entrada[0])
    x = int(entrada[1])
    a = min(int(entrada[2]), int(entrada[3]))
    b = max(int(entrada[2]), int(entrada[3]))

    while(x != 0):
        if(a > 1):
            a -= 1
        elif(b < n):
            b -= 1
        x -= 1
    print(abs(a-b))
