n = int(input())
l = list(map(int, input().split()))
count = 0
s = 0

while n > 0:
    n -= l[count]
    count += 1
    s += 1

    if count == 7:
        count -= 7
    
    if s > 7:
        s -= 7

print(s)