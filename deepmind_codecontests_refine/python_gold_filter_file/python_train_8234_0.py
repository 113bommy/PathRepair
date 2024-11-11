n,r = (int(i) for i in input().split())

count = 0
arr = []
br = 0
for i in input().split():
    arr.append([0, int(i)])

for i in range(n):
    cur = arr[i]
    if cur[0]==0:
        maxind = -1
        for j in range(max(i-r,0), min(i+r, n)):
            if arr[j][1]==1:
                maxind = j
        if maxind==-1:
            br = 1
            break
        arr[maxind][1]=2
        count+=1
        for j in range(max(maxind-r,0), min(maxind+r, n)):
            arr[j][0] = 1

if br:
    count = -1

print(count)


