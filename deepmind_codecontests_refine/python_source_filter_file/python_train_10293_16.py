N = int(input())
A = list(map(int, input().split()))

s = 200**2 * 10
for x in range(min(A), max(A)+1):
    s = min(s, sum((x-a)**2 for a in A))
print(s)
