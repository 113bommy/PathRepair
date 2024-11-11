n = int(input())
s = input().split()
a = []
l=0
last = 0
for i in s: 
    a.append(int(i)-last)
    last = int(i)
ans = ''
for i in range(n):
    array = a[:i+1]
    arr = []
    while (len(arr) < n):
        for j in array: 
            if (len(arr) < n): arr.append(j)
    if (arr == a): 
        l += 1
        ans += str(i+1) + ' '
print(l)
print(ans)