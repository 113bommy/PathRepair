n = int(input())
for _ in range(n):
    k, x = [int(i) for i in input().split()]
    if k==1:
        print(x)
    else:
        print(x+(k-1)*9)