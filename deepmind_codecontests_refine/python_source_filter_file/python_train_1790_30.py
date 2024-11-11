inp = int(input())
for i in range(inp):
    n = int(input())
    if n == 2 :
        print('2')
    elif n % 2 == 0 :
        print(n)
    else :
        print(n + 1)
