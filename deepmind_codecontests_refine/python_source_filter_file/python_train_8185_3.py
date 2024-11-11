from sys import stdin, stdout

def find(num):
    x = []
    while req[num] > 0:
        x.append(num)
        num = req[num]
    for i in x:
        req[i] = num
    return num

def union(a, b):
    A, B = find(a), find(b)
    if A != B:
        if req[A] > req[B]:
            A, B = B, A
        req[A] += req[B]
        req[B] = A

n = int(stdin.readline().strip())
req = [-1]*(n+1)
a = [int(num) for num in stdin.readline().strip().split()]
b = [int(num) for num in stdin.readline().strip()]
req = [b[0]]
index = [-1]*(n+1)
for i in range(1, n-1):
    req.append(req[-1]+b[i])
req.append(req[-1])
dupli_a = sorted(a)
condn = True
for i in range(n):
    index[a[i]] = i
for i in range(n):
    if a[i] != dupli_a[i]:
        l = min(index[a[i]], index[dupli_a[i]])
        r = max(index[a[i]], index[dupli_a[i]])
        if b[l]==1:
            cur_sum = req[r] if l == 0 else req[r]-req[l-1]
            if cur_sum < r-l:
                condn = False
                break
            elif cur_sum==r-l and (r+1==n or b[r]!=0):
                condn = False
                break     
        else:
            condn = False
            break

if condn:
    stdout.write("YES")
else:
    stdout.write("NO")
