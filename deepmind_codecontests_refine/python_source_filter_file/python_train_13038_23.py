n = int(input())
for i in range(n):
    a,b = map(int, input().split())
    print((a-1)//b+1)