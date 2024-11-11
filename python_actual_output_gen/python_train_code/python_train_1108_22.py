a, b = list(map(int, input().split()))

count = 0
while a <= b:
    a += a
    b += 2
    count+=1

print(count)
