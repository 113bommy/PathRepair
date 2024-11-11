a, b = map(int, input().split())
if b == 1:
    print(a*(a-1)//2, a*(a-1)//2)
elif a == b:
    print(0, 0)
else:
    k = int(a // b)
    k1=a%b
    if a % b == 0:
        print((k*k-1* b)//2, (a-b)*(a - b + 1)//2)
    else:
        print(b * k*(k-1)//2 + k1 * k, (a-b+1)*(a-b)//2)
