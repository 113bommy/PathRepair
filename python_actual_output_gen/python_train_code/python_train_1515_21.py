a = input().split()
for i in range(len(a)):
    a[i] = int(a[i])
c = 0
sum = 0
for i in range(a[2]):
    sum =sum + 2*(a[1]-2-c)+(a[0]-2-c)*2
    c+=2
print(sum)
