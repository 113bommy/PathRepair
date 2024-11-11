n, m = map(int, input().split())
a = list(map(int, input().split()))
a.append(0)
a.sort()
x=0
b=0
for i in range(1, n):
    if a[i]!=a[i-1]:
        b+=1
    x+=1
x+=a[-1]-b
if a[-1]-b==0:
    x+=1
print(sum(a)-x)