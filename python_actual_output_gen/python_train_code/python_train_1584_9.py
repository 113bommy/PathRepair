n = int(input())
L = [int(x) for x in input().split()]

s = sum(L)
total = 0
index = 0
while 2*s < 9*n:
    if L[index] != 5:
        s += 5-L[index]
        total += 1
    index += 1

print(total)