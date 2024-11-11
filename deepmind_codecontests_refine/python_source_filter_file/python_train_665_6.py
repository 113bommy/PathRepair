# (n, k) = map(int, input().split(' '))
# arr = list(map(int, input().split()))

n = int(input())
p = 1
i = 0
j = n-1
p1 = 0
p2 = 0
arr = list(map(int, input().split()))

while i < j:
    gr = 0
    if arr[i] > arr[j]:
        gr = arr[i]
        i = i + 1
    else:
        gr = arr[j]
        j =j - 1
    if p % 2 == 0:
        p2 = p2 + gr
    else:
        p1 = p1 + gr
    p += 1
    if i == j:
        if p % 2 == 0:
            p2 = p2 + arr[i]
        else:
            p1 = p1 + arr[i]
if n == 1:
    print(str(1)+" "+str(1))
else:
    print(str(p1) + " " + str(p2))