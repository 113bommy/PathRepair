n = int(input())

hashmap = [0, 1]

for i in range(2, 48)   : 
	hashmap.append(hashmap[i-1] + hashmap[i-2])

# print(hashmap)

inde = hashmap.index(n)

if inde > 3:
	print(hashmap[inde -1], hashmap[inde-3],hashmap[inde- 4    ])
elif inde == 3:
	print(0,1,1)
elif inde == 2:
	print(0, 0, 1)
elif inde == 1: 
	print(0, 0, 1)
else:
	print(0, 0, 0)