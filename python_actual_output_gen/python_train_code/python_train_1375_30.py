n = int(input())
t = n
magnets = list()
while t:
    magnets.append(input())
    t -= 1

group = 0
slider = magnets[0]

for i in range(1, n):
    # print(slider, magnets[i])/
    if slider != magnets[i]:
        print(slider, magnets[i])
        slider = magnets[i]
        group += 1

print(group + 1)