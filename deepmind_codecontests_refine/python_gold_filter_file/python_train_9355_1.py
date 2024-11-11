import sys

cars = []
for line in sys.stdin:
    car = int(line)
    if car:
        cars.append(car)
    else:
        print(cars.pop())