
n = int(input())

for i in range(n):
    a , b = input().split()
    a = int(a)
    b = int(b)
    if a % b == 0:
        print(a)
    elif a == 1:
        print(1)
    else:
        print((a - (a % b)) + min((b // 2) , (a % b)))