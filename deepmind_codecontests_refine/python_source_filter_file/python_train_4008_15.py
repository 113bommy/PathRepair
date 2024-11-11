n, w = map(int, input().split())

a = list(map(int, input().split()))

a.sort()

ans = 0

if(a[0]*2 > a[n]):
    ans = ((a[n]/2)*n) + a[n]*n

else:
    ans = (a[1]*n) + (a[1]*2*n)

print(w if ans>w else ans)



