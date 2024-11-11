t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    if sum(a)%2==0:
        print(0)
    else:
        print(1)