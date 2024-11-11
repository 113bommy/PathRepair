# Problem Link: https://codeforces.com/problemset/problem/108/A
# Author: Raunak Sett
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__

# do magic here

time = input()
palindromeTimes = ["01:10", "02:20", "03:30", "04:40", "05:50", "06:60", "10:01", "11:11", "12:21", "13:31", "14:41", "15:51", "20:02", "21:12", "22:22", "23:32", "00:00"]

solved = False
for i in range(len(palindromeTimes)):
    ptime = palindromeTimes[i]
    if ptime > time:
        print(ptime)
        solved = True
        break
if not solved:
    print("00:00")