import math
case=int(input())
for _ in range(case):
    num, floors=map(int, input().split(" "))
    if floors<=2:
        print(1)
    else:
        num-=2
        print(math.ceil(num/floors)+1)
