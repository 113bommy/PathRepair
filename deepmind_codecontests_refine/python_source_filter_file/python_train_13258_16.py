s, n = map(int,input().split())

dragons = []

for i in range(n):
    x,y = map(int,input().split())

    dragons.append([x,y])

dragons.sort()

#print(dragons)

energy = s

for dragon in dragons:
    #energy = energy - dragon[0]
    if(energy<dragon[0]):
        print("NO")
        exit()
    energy = energy + dragon[1]

print("YES")
