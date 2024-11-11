n,k = input().split()
n = int(n)
k = int(k)
z = 0
a = [int(i) for i in input().split()]
for i in range(len(a)):
    if a[i] >= a[k-1] and a[k-1] != 0:
        z += 1
print(z)