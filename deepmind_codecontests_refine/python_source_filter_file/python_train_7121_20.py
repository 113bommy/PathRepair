n = int(input())
#n, m = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
s = sum(c)
l = n - s // 5
if l == n:
    print(-1)
else:
    k = s // 45
    s = '5' * 9 * k
    s += '0' * l
    print(s)
    