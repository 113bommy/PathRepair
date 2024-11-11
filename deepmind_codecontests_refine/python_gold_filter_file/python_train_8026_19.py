n = int(input())
dis = []
for i in range(n):
    a, b = map(int, input().split())
    dis.append(a+b)
print(max(dis))