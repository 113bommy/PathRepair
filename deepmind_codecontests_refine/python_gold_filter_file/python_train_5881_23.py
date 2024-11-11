digit = int(input())
originalState = input()
combination = input()
diffl = []
ol = [x for x in originalState]
cl = [y for y in combination]
for i in range(len(ol)):
    diff = abs(int(ol[i])-int(cl[i]))
    if diff>5:
        diff = 10 - diff
        diffl.append(diff)
    else:
        diffl.append(diff)        
summ = 0
for l in diffl:
    summ += l
print(f"{summ}")
    
    
