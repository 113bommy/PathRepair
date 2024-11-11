from math import trunc

inputting = list(map(int, input().split()))
n = inputting[0]
b = inputting[1]
d = inputting[2]
oranges = list(map(int, input().split()))
counter = 0
juicing = 0
for i in oranges:
    if i <= b:
        counter += i
    if counter > d:
        juicing += 1
        counter = 0
print(juicing)