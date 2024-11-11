n = int(input())
a = [0]*n

a = list(map(int,input().split()))

max = 0
length = 1
t = a[0]

for i in range(1,n):
    if a[i] <= 2*t:
        t = a[i]
        length += 1
    else:
        t = a[i]
        length = 1
    if length > max:
        max = length

print(max)
