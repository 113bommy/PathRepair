from math import sqrt
def ans(a):
    if a % 2 == 0:
        print(a // 2, a // 2)
    else:
        for i in range(2, int(sqrt(a//2)+2)):
            if a % (i) == 0:
                print(a // i, a - (a // i))
                return
        print(1,a-1)
for _ in range(int(input())):
    a=int(input())
    ans(a)