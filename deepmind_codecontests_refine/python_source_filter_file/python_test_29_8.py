t = int(input())
for i in range(t):
    n = int(input())
    a = [int(a) for a in input().split()]
    s = sum(a)
    print(a.count(1)*(a.count(0)+1))