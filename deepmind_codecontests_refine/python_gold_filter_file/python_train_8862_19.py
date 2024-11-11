from sys import stdin,stdout
n = int(stdin.readline())
a = list(map(int,stdin.readline().split()))
a.sort()
b = 0
j=0
for i in range(n):
    #j=i
    while j < n and a[j] - a[i] <= 5:
        j = j + 1
        b = max(b,j - i)
stdout.write(str(b)+"\n")