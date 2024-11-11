tasks=input()
n,m=[int(i) for i in tasks.split()]
a=input().split()
time=int(a[0])-1

for i in range(1,m):
    if int(a[i])>=int(a[i-1]):
        time+=int(a[i])-int(a[i-1])
    else:
        time+=n-int(a[i-1])+int(a[i])

print(time)
