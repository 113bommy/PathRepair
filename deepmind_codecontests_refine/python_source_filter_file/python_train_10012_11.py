T = int(input())
for kase in range(T):
    n = int(input())
    lis = [int(x) for x in input().split()]
    lis.sort()
    print(max(n-2,lis[-2]-1))