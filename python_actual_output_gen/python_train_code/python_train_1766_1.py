n = int(input())
a = [int(x) for x in input().split(' ')]

k = 0

for i in range(n-5):
    if a[i] == 1 and a[i+1] == 0 and a[i+2] == 1 and a[i+3] == 0 and a[i+4] == 1:
        a[i+2] = 0
        k += 1
        
for i in range(n-2):
    if a[i] == 1 and a[i+1] == 0 and a[i+2] == 1:
        a[i] = 0
        k += 1

print(k)