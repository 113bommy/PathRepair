n = int(input())
a = list(map(int,input().split()))
ans = 0
while all(A%2 == 0 for A in a):
 a = (i/2 for i in a )
 ans += 1
print(ans)