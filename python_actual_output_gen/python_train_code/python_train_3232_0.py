n,k,m = map(int,input().split())
arr = sorted(list(map(int,input().split())))
csum = [0]
for i in arr:
    csum.append(csum[-1]+i)

def f(i):
    return ((csum[-1]-csum[i])+min(m-i,k*(n-i)))/(n-i)

max = 0
for i in range(min(m,n)):
    if f(i) > max:
        max = f(i)
print(max)