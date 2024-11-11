
def ans(ar,n):
    k = max(ar)
    for i in range(1,len(ar)-1):
        if ar[i]==k and (ar[i-1]<k or ar[i+1]<k):
            return i+1
    if ar[0]==k:
        return 1
    else:
        return n

for _ in range(int(input())):
    n = int(input())
    ar = [int(i) for i in input().split()]
    if min(ar)==max(ar):
        print(-1)
    else:
        print(ans(ar,n))