"""output= ""
lowest = []
biggest=[]
sample = "ABC"
for x in range(3):
    s = input()
    if s[1] == '>':
        biggest.append(s[0])
        lowest.append(s[2])
    else:
        lowest.append(s[0])
        biggest.append(s[2])
for i in lowest:
    if lowest.count(i) ==2:
        output += i
        break
for y in lowest:
    if y not in output:
        output += y
for z in sample:
    if z not in output:
        output += z
if
print(output,lowest,biggest)"""

n = int(input())
soldier_1 = list(map(int,input().split()))
soldier_1 = soldier_1[1:]
soldier_2 = list(map(int,input().split()))
soldier_2 = soldier_2[1:]
unfinished = True
counter = 0
checker = len(soldier_1)+ len(soldier_2)
while unfinished:
    if soldier_1[0] > soldier_2[0]:
        soldier_1.append(soldier_2[0])
        soldier_1.append(soldier_1[0])
        soldier_2.remove(soldier_2[0])
        soldier_1.remove(soldier_1[0])
        counter +=1
    elif soldier_1[0] < soldier_2[0]:
        soldier_2.append(soldier_1[0])
        soldier_2.append(soldier_2[0])
        soldier_1.remove(soldier_1[0])
        soldier_2.remove(soldier_2[0])
        counter += 1
    if counter >= 100:
        print(-1)
        break
    if len(soldier_1) == checker:
        print(counter,1)
        unfinished = False
    elif len(soldier_2) == checker:
        print(counter,2)
        unfinished = False
