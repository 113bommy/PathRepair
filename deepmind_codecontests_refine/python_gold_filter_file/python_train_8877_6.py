test = int(input())
for _ in range(test):
    a,b,c,d = map(int, input().split())
    print(max(a+b, c+d))
