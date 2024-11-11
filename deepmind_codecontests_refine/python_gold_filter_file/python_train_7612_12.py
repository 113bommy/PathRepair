
[n,l,r] = [int(x) for x in input().split()]



diff_3 = (r - l)//3
ways = [diff_3,diff_3,diff_3]

for i in range(l,r-diff_3*3+1):
    # print(i)
    ways[i%3] += 1


# print(ways)
# print(sum(ways), r-l + 1)

curr = [ways[0],ways[1],ways[2]]
# print(curr)
for i in range(n-1):
    new = [0,0,0]
    for j in range(0,3):
        for k in range(0,3):
            new[(j+k)%3] += (ways[j]*curr[k])
    for j in range(0,3):
        new[j] %= (10**9+7)
    curr = new
    # print(curr)

print(curr[0])