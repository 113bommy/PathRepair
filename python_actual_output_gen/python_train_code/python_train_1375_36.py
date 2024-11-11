n = int(input())
groups = 0
last = input()
for i in range(0, n-1):
    m = input()
    if m == last:
        groups+=1
    last = m
print(groups)
