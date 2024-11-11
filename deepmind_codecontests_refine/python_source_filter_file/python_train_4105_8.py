bidders = int(input())
bids = [int(x) for x in (input().split(" "))]

high = 0
second = 0
pos = 0

for i in range(0, len(bids)):
    if int(bids[i]) > high:
        position = i + 1
        second = high
        high = bids[i]
    if bids[i] > second and bids[i] < high:
        second = bids[i]

print(position, high)
