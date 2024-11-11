n=int(input())
for i in range(n):
    r = [int(x) for x in input().split()]
    print(r[1]//((r[0]+1)//2))