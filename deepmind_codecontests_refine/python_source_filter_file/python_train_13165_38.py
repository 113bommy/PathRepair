n = input().strip()
l = [2,7,1,3,3,4,2,5,1,2]
k = 1
for i in range(2):
    k = k * l[int(n[i])]
print(k)