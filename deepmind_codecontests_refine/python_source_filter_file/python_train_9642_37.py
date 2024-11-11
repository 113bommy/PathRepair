n = int(input())
stay = input()

flight_SF = 0
flight_FS = 0

for i in range(n-1):
    if (stay[i] == 'F') & (stay[i] == 'S'):
        flight_FS += 1
    elif (stay[i] == 'S') & (stay[i] == 'F'):
        flight_SF += 1
        
if flight_SF > flight_FS:
    print('YES')
else:
    print('NO')
