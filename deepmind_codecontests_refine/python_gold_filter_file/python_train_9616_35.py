n = int(input())
data = list(map(int, input().split()))
a = []

for i in range(n):
    a.append(data[i]%2)
if a.count(0)>a.count(1):
    print(a.index(1)+1)
else:
    print(a.index(0)+1)