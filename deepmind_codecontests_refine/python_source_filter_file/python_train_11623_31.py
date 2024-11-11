sizes = [int(i) for i in input().split()]
fat = sizes[0]
mot = sizes[1]
son = sizes[2]
m = sizes[3]

fat_specs = [max(fat, 2*m),fat*2]
mot_specs = [max(mot, 2*m),mot*2]
son_specs = [max(son, m),min(son*2, m*2)]
if fat<m or mot<m:
    print(-1)
else:
    if fat_specs[1]-fat_specs[0]>-1 and mot_specs[1]-mot_specs[0]>-1 and son_specs[1]-son_specs[0]>-1:
        print(fat_specs[0], mot_specs[0], son_specs[0], sep = "\n")
    else:
        print(-1)


