n = int(input())
A = input().split()
print(A)
maxi = 0
for i in A:
    summ = 0
    for j in i:
        if ord('A') <= ord(j) <= ord('Z'):
            summ += 1
    maxi = max(maxi, summ)
print(maxi)