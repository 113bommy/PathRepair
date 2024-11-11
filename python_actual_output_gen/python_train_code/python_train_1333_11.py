n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
med = a[n//2:]

i = 0
mn = a[0]

for i in range(len(med)-1):
    if k >= (i+1)*(med[i+1]-med[i]):
        k -= (i+1)*(med[i+1]-med[i])
        mn = med[i+1]
    else:
        mn += k//(i+1)
        k = 0
        break
        
mn += k//len(med)
        
print(mn)