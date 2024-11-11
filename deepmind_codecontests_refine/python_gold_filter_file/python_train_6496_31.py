
n,m = map(int,input().split(" "))
a = [1] + list(map(int,input().split(" ")))
count = 0

for j in range(1,m+1):
    i = a[j-1]
    if a[j]>i:
        count+= a[j]-i
    elif a[j]<i:
        count+= n -(i-a[j])


print(count)


