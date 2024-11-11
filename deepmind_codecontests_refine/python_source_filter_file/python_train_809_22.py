N = int(input())
a = list(map(int, input().split()))

ans = a[0]
for i in range(1,N):
    ans ^= a[i]

if(ans == 0):
    print("Yes")
else:
    print("No")
