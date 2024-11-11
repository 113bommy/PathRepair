import sys
n = int(input())
count = 0
seats = []

for i in range(n):
    seats.append(sys.stdin.readline().strip("\n"))

for i in range(n):
    if count == 0 and seats[i].count("00"):
        seats[i] = seats[i].replace("00", "++")
        count = 1
    else:
        continue

if count == 1:
    print("YES")
    for i in seats:
        print(i)

else:
    print("NO")