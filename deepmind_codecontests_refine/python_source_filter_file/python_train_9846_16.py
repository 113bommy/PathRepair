input()
m = map(int, input().split())
counter = 0
for i in m:
    counter += (max(m) - i)
print(counter)
