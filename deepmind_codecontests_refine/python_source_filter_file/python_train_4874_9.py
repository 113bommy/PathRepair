n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
k = []
j = 0
na= 0
c = 0
for i in range(n):
    if a[i]<b[i]:
        na +=b[i]-a[i]
        c+=1
    elif a[i] > b[i]:
        k.append(a[i]-b[i])
    k.sort()
while na > 0 and k:
    na -=k[-1]
    k.pop(-1)
    c +=1
if na > 0:print(-1)
else:print(c)