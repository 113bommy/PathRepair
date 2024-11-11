n = int(input())
a = list(map(int, input().split()))
l = [0] * n
for i in a:
    l[i-1] += 1
    
al = 0
for i in l:
    al += i*(i-1)//2

for k in range(n):
    print(al - (l[a[k]] - 1))