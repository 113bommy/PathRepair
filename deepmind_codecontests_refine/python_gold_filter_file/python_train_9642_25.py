num_flights = int(input())
flight = input()
numSF = 0
numFS = 0
for x in range(1,len(flight)):
    if flight[x-1] == 'S' and flight[x] == 'F':
        numSF += 1
    if flight[x-1] == 'F' and flight[x] == 'S':
         numFS += 1
if numSF > numFS:
    print("YES")
else:
    print("NO")