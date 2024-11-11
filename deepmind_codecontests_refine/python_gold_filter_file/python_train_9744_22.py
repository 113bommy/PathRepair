n, k = input().split()
n = int(n)
k = int(k)
s = [int(x) for x in input().split()]
punkty = 0
for x in s:
    punkty+= k-x
print(max(punkty*2-n,0))