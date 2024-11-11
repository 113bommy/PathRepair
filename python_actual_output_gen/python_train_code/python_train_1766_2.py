#1077B
n = int(input())
a = list(map(int, input().split(" ")))
k = 0
count = 0
while k < n -3:
    if a[k] == 1 and a[k+1] == 0 and a[k+2] == 1:
        count += 1
        k += 3
    else:
         k += 1
print(count)
