n, x = map(int, input().split())
if(n == 1):
    print("YES")
    print(x)
elif(n == 2):
    if(x == 0):
        print("NO")
    else:
        print("YES")
        print(0, x)
else:
    print("YES")
    res = 0
    for i in range(1, n-3):
        print(i, end = " ")
        res ^= i
    print(1<<18, end = " ")
    print(1<<17, end = " ")
    print(x ^ (1 << 18) ^ (1 << 17) ^ res)
    

