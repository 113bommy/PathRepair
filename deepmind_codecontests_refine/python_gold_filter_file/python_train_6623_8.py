#n = int(input())
n, k, x = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
s = 0
for i in range(n - k):
    s += c[i]
s += k * x
print(s)