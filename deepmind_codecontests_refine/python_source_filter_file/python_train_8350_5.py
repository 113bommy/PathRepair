#Codeforces
#Calculate number of minutes left 

''' 0<= h <= 24 , 0 <= m <= 60 '''
def calc_mins(hours,mins):
    left = 0
    if hours > 24:
        hours %= 24
    elif hours < 24 and hours >= 0:
        if hours == 23:
            left = 0
        else:
            left+=(24-hours)*60-60
    
    if mins > 60:
        mins %= 60
    elif mins < 60 and mins >= 0:
        if mins == 0:
            left = 60
        else:
            left+=(60-mins)
    return left 




no_of_tcs = int(input())
hrs = []
mins = []
for i in range(no_of_tcs):
    a, b = map(int, input().split())
    hrs.append(a)
    mins.append(b)
for i in range(len(hrs)):
    print(calc_mins(int(hrs[i]),int(mins[i])))
