i = int(input())
l = list(map(int,input().split()))
c = 0
for num in l:
    if num % 2 != 0:
        c += 1
if c%2 != 0:
    print(1)
elif c%2 == 0:
    print(i-c)