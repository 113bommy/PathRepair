numOfCities, pos = [int(x) for x in input().split()]
criminals = [int(x) for x in input().split()]
CriminalsCought = 0
max_dist = pos-1 if pos > numOfCities//2 else numOfCities-pos
if criminals[pos-1] == 1: CriminalsCought+=1
for i in range(1,max_dist+1):
    if pos-1-i < 0 or pos-1+i > numOfCities-1:
        if pos > numOfCities//2: 
            if criminals[pos-1-i] == 1: CriminalsCought+=1
        else:
            if criminals[pos-1+i] == 1: CriminalsCought+=1
    else:
        if criminals[pos-1+i] == 1 and criminals[pos-1-i] == 1:
            CriminalsCought +=2
        
print(CriminalsCought)