n,t = map(int,input().split())
a = []
a = input().split()
for i in range(n):
    a[i] = int(a[i])
time = 0
k = 0
for i in range(n):
    time += t - a[i]
    k +=1
    if time >= t:
        break
print(k)