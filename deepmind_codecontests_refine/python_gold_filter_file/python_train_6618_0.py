#! /usr/bin/python3

name = input()
lines = int(input())

points = {
	"posted" : 15,
	"commented": 10,
	"likes": 5,
}

people = {}

for _ in range(lines):
	line = input().strip().split()
	name1 = line[0]
	name2 = ''
	command = line[1]
	if command == "likes":
		name2 = line[2][:-2]
	else:
		name2 = line[3][:-2]

	if name2 == name:
		name1, name2 = name2, name1

	if name1 != name and (not name1 in people):
		people[name1] = 0
	if name2 != name and (not name2 in people):
		people[name2] = 0


	if name1 == name:
		people[name2] += points[command]



people_list = [(-people[x], x) for x in people]
people_list.sort()


for x, y in people_list:
	print(y)
