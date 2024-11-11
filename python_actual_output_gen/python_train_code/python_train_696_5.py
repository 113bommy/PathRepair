a=[]
n = int(input())
a = map(int,input().split())
a = list(a)
b=[]
for i in range(n):
    if a[i] not in b:
        b.append(a[i])
print(b)
if len(b) > 3:
    print(-1)
elif len(b) == 3:
    if b[2] - b[1] == b[1] - b[0]:
        print(b[1] - b[0])
    else:
        print(-1)
elif len(b) == 2:
    if (b[1] - b[0]) % 2 == 0:
        print((b[1] - b[0])//2)
    else:
        print(b[1] - b[0])
else:
    print(0)