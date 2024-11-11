n, k = map(int, input().split())
arr = list(map(int, input().split()))
if n == 1:
    print(arr[0] + k)
    exit(0)
arr.sort()
mid = n // 2
piv = mid + 1
maxm = arr[piv]
delta = arr[mid + 1] - arr[mid]
while k >= delta:
    k -= delta
    maxm = arr[piv]
    piv += 1
    if piv >= n:
        break
    delta = (piv - mid) * (arr[piv] - maxm)
    #print('d', delta, piv, maxm, k)
#print(k)
if piv != mid:
    maxm += k // (piv - mid)
print(maxm)
