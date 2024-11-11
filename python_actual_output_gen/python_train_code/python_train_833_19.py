n=int(input())
l=[int(x) for x in input().split()]
count = 0
if n == 1 or n == 2:
    print(0)
else:
    for i in range(1,n-1):
        if l[i-1] < l[i] < l[i+1] or l[i-1] > l[i] > l[i+1]:
            count += 1
    print(count)