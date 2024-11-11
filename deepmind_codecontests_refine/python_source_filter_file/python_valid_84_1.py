l = int(input())
for i in range(l):
    n, s = map(int, input().split())
    print(s//((n+1)//2))