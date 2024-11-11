n, k = map(int, input().split())

arr = [int(z) for z in input().split()]

cap = 1001

potentialfirst=[]
ops = []

for pot in range(1,cap):
    cnt = 0
    r = []
    for i in range(n):
        if arr[i] != pot+i*k: cnt += 1
        if arr[i] < pot+i*k:
            r.append(['+', str(i+1), str(abs(arr[i] - (pot+i*k)))])
        elif arr[i] > pot+i*k:
            r.append(['-', str(i + 1), str(abs(arr[i] - (pot+i*k)))])
    potentialfirst.append(cnt)
    ops.append(r)

ind = potentialfirst.index(min(potentialfirst))
print(potentialfirst[ind])
for i in ops[ind]:
    print(' '.join(i))
