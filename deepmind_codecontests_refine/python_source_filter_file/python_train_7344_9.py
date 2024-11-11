_, b, d = map(int, input().split())
a = list(map(int, input().split()))

count = 0
waste = 0

for i in a:
    if i < b:
        waste += i

    if waste > d:
        count += 1
        waste = 0

print(count)