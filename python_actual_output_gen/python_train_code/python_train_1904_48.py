M = int(input())
a = 0
csum = 0
for i in range(M):
    d,c = map(int, input().split())
    a += d*c
    csum += c
print(a // 9 + 1 + csum - 2)