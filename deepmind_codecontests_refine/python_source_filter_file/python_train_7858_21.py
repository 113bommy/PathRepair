n = int(input())
dem =1
max = 0
mang = [int(nhap) for nhap in input().split()]
for i in range(1,len(mang),1):
    if mang[i] >= mang[i-1] :
        dem+=1
    else:
        dem=1
    if (dem > max):
        max = dem
print(max)