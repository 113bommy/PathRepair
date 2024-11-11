n = int(input())
a = [int(x) for x in input().split(" ")]
count = 0

if n == 2:
    print(0)
else:
    least = min(a)
    largest = max(a)

    for x in a:
        if not(x == least or x == largest):
            count += 1
print(count)

