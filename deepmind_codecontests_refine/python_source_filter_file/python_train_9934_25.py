s = input()
t = input()
hour1 = int(s[0])*10 + int(s[1])
min1 = int(s[3])*10 + int(s[4])
hour2 = int(t[0])*10 + int(t[1])
min2 = int(t[3])*10 + int(t[4])
if min1 < min2:
    min3 = min1 + 60 -min2
    if hour1 == 0:
        hour1 = 23
    else:
        hour1 -= 1
else:
    min3 = min1 - min2
if hour1 < hour2:
    hour3 = hour1 + 24 -hour2
else:
    hour3 = hour1 - hour2
if hour3 < 9:
    print('0'+str(hour3)+':',end='')
else:
    print(str(hour3) + ':', end='')
if min3 < 9:
    print('0'+str(min3))
else:
    print(str(min3))