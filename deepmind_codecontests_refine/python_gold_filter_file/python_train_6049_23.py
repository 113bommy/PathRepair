n = [int(k) for k in input().split()]
m = [int(k) for k in input().split()]
b = min(n[1],n[2])
c = True
a = 0
for k in range(int(n[0]/2)):
    if m[k] == 1 and m[n[0]-1-k] == 1:
        continue
    elif m[k] == 1 and m[n[0]-1-k] == 2:
        a += n[2]
    elif m[k] == 0 and m[n[0]-1-k] == 0:
        continue
    elif m[k] == 0 and m[n[0]-1-k] == 2:
        a += n[1]
    elif m[k] == 2 and m[n[0]-1-k] == 2:
        a += 2*b
    elif m[k] == 2 and m[n[0]-1-k] == 1:
        a += n[2]
    elif m[k] == 2 and m[n[0]-1-k] == 0:
        a += n[1]
    else:
        c=False
        break
if c:
    if n[0] % 2 == 0:
        print(a)
    elif m[int(n[0]/2)] == 2:
        print(a + b)
    else:
        print(a)
else:
    print(-1)