#n = int(input())
n, m, k = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
n = abs(n)
m = abs(m)
if m + n >= k and (m + n) % 2 == k % 2:
    print('Yes')
else:
    print('No')