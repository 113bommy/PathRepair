h1,a1,c1 = map(int,input().split())
h2,a2 = map(int,input().split())
actions = [0]*10000
j = 0

while h2 >= 0:
    if h2 <= a1:
        actions[j] = 1
        j += 1
        break
    if h1 <= a1:
        actions[j] = 2
        j += 1
        h1 += c1 - a2
        continue
    actions[j] = 1
    j += 1
    h1 -= a2
    h2 -= a1

print(j)
for i in range(j):
    if actions[i] == 1:
        print("STRIKE")
    elif actions[i] == 2:
        print("HEAL")
    
