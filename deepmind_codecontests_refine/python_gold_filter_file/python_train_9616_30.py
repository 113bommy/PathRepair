#----------------------------------------------------
#   = = >  CCCCooodddeeefffooorrrccceeesss  < = =
#----------------------------------------------------
n = int(input().split()[0])
mm = list(map(int, input().split()))
sod = 0
juft = 0
l = 0
k = 0
for i in range(n):
    if mm[i] % 2 == 0:
        juft += 1
        l = i + 1
    else:
        k = i + 1
        sod += 1
if sod > juft:
    print(l)
else:
    print(k)