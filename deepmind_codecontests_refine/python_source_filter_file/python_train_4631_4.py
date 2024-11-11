#n = int(input())
#n, m = map(int, input().split())
s = input()
#c = list(map(int, input().split()))
k = 0
for i in range(len(s) - 1):
    m = int(s[len(s) - i - 1])
    k += min(9 - m, m) * (10 ** i)
m = int(s[0])
if 9 - m == 0:
    m = int(s[0])
else:
    m = min(m, int(s[0]))
k += m * 10 ** (len(s) - 1)
print(k)