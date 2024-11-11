from math import ceil
n = int(input())
l = [1,2,3,4,5]
i,k = 5,2
check = 6
s = ["Sheldon","Leonard","Penny","Rajesh","Howard"]

if n<=5:
    check = n-1
else:
    while True:
        for j in range (len(l)):
            if j == 0:
                l[j]+=i
            else:
                l[j] = l[j-1] + k
        i*=2
        if l[0] <= n and n <= l[0]+(i//5):
            check = 0
            break
        elif l[1] <= n and n <= l[1]+(i//5):
            check = 1
            break
        elif l[2] <= n and n <= l[2]+(i//5):
            check = 2
            break
        elif l[3] <= n and n <= l[3]+(i//5):
            check = 3
            break
        elif l[4] <= n and n <= l[4]+(i//5):
            check = 4
            break
        k*=2

print(s[check])