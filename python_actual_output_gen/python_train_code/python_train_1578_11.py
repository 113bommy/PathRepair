n = int(input())
L = list(map(int,input().split()))
L.sort()
if n%2 == 1:
    ans = n//2 - 1
else:
    ans = n//2

print(L[ans])