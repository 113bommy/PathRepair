stops = int(input())
curr = 0
seats = 0
for i in range(stops):
    dbo , bo = list(map(int,input().split()))
    dbo = abs(curr-dbo)
    curr = curr + bo
    if seats < curr:
        seats = curr

print(seats)