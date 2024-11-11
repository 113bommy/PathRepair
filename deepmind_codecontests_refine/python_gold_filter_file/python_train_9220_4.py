n = int(input())
home = input()
flights = {}
for x in range(n):
    flight = input()
    places = flight.split("->")
    a = places[0]
    b = places[1]
    if not a in flights:
        flights[a] = []
    flights[a].append(b)
place = home
while place in flights:
    if len(flights[place]) == 0:
        break
    temp = flights[place][0]
    del flights[place][0]
    place = temp
if place == home:
    print("home")
else:
    print("contest")