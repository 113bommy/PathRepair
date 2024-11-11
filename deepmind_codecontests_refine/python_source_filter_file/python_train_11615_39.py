#Broken Clock
#722A
#http://codeforces.com/problemset/problem/722/A

clockFormat = input()
brokenTime = input()

parts = brokenTime.split(":")
hours = int(parts[0])
minutes = int(parts[1])

if minutes > 59:
    #if time is greater than 59, then change the first digit to 0
    minutes = "0" + brokenTime[-1:]
else:
    minutes = parts[1]


if clockFormat == "12":
    #12 hour format
    #hours 1-12
    if hours == 0:
        hours = "01"
    elif hours > 12:
        if parts[0][1:3] == "0":
            hours = "10"
        else:
            hours = "0" + brokenTime[1:3]
    else:
        hours = parts[0]
else:
    #24 hour format
    if hours > 23:
            hours = "0" + brokenTime[1:3]
    else:
        hours = parts[0]


print(str(hours) + ":" + str(minutes))