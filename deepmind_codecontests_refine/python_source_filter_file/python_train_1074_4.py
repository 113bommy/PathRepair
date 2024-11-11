n =int(input())
r= sorted(list(map(int, input().split())))
pi = 3.1415926536
sum =0
for i in range(n-1, 0, -2):
    sum+=r[i]**2-r[i-1]**2
if n&1:
    sum+=r[0]
print(pi*sum)
