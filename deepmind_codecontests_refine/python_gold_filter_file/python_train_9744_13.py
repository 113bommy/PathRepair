n, k = map(int, input().split())
a, counter = sum(map(int, input().split())), 0
while k - a / n > .5:
        a += k
        n += 1
        counter += 1
print(counter)
