n, a, b = map(int, input().split())

if (b-a) % 2 == 0:
    print((b-a) // 2)
else:
    print(min((a+b-1)//2, (n*2-a-b+1)))