n = int(input())
print('YES')
for i in range(n):
    a,b,c,d = map(int,input().split())
    print((a&1) * 1 + (b&1) * 2)
