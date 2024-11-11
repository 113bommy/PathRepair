n ,m = map(int, input().split())
x = [int(i) for i in input().split()]
t = 0
for i in range(m-1):
    if x[i+1] < x[i]:
        t += 1
if t > 0:
    print(t*(n-1)+x[m-1])
else:
    print(x[m-1]-1)
