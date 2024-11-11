n = int(input())

room = []
count = 0
for i in range(n):
    a = list(map(int,input().split()))
    if a[0] < a[1]:
        count += 1

print(count)
