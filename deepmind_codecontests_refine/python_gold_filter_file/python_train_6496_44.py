n,m=[int(i)for i in input().split()]
house=[int(i)for i in input().split()]
step=house[0]-1
for i in range(1,m):
    if house[i]>=house[i-1]:
        step+=house[i]-house[i-1]
    else:
        step+=n-house[i-1]+house[i]
print(step)
