n = int(input())
a = list(map(int,input().split()))
count = 0

for i in range(n):
    minij =i
    for j in range(i,n):
        if a[j] < a[minij]:
            minij = j
    if a[i] > a[minij]:
        count+=1
        a[i],a[minij] = a[minij],a[i]
        print(' '.join(map(str,a)))

print(count)

