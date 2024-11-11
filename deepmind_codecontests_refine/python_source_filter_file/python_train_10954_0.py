n = int(input())
b = [int(ele) for ele in input().split()]

diff = {}
for i in range(n):
    diff[b[i]-i] = 0

for i in range(1,n):
    diff[b[i]-i] += b[i]

maxi = 0
for key in diff.keys():
    maxi = max(maxi, diff[key])
print(maxi)
