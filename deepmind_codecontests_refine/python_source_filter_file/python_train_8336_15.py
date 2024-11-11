
from collections import defaultdict

ka = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824]
#
# for i in range(100):
#     if 2**i<=2*(10**9):
#         ka.append(2**i)
#     else:
#         break
# print(ka)
hash = defaultdict(int)

n = int(input())

l = list(map(int,input().split()))

for i in l:
    hash[i]+=1

l = set(l)
ans = 0
for i in l:
    flag = 0
    for j in ka:
        if j-i in l:
            if j-i == i:
                if hash[i]>1:
                  flag = 1
                  break
            else:
                flag = 1
                break
    if not flag:
        ans+=1

print(ans)

