q = int(input())
for i in range(q):
    a, b, c = map(int, input().split())
    s = a + b + c
    print(s // 2)