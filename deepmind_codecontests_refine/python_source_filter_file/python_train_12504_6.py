n,k = list(map(int,input().split()))
arr = list(map(int,input().split()))
arr.sort()
out = [0]*(arr[-1])
h = 0
for i in range(n):
    while h < arr[i]:
        out[arr[-1] - h - 1] = n-i
        h+=1
tot = 0
ind = 0

l = len(out)
c = 0
for i in range(l-1,0,-1):
    if out[-1] == out[i]:
        c = i
out = out[:c]
l = len(out)
count = 0
while ind < l:
    while tot + out[ind] <= k:
        tot+=out[ind]
        ind+=1
        if ind == l:
            break
    count+=1
    tot = 0
print(count)

