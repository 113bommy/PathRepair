n = int(input())
lst = list(map(int,input().split()))
x = 0
a = 0
lst.sort()
for i in lst:
    if i >= x:
        a += 1
        x += i
print(a)