n = int(input())								# number of lines
x1, x2 = [float(x) for x in input().split()] 	# strip frontier's values

delta = 0.001
y1 = list()
y2 = list()

# Adjust x1 and x2 in order to ignore points that cross exactly on the line x1 or x2
# Shorten the the frontier [x1, x2]
# new_x1 = x1 + delta
# new_x2 = x2 - delta
new_x1 = x1 + delta
new_x2 = x2 - delta

for i in range(n):
	k, b = [int(x) for x in input().split()]

	# Calculate the Y(x1) for the line i
	y1.append( (i, k*new_x1 + b) ) 
	# Calculate the Y(x2) for the line i
	y2.append( (i, k*new_x2 + b) ) 

y1.sort(key=lambda x:x[1]) # sorting by yi
y2.sort(key=lambda x:x[1]) # sorting by yi

has_intersection = False
for i in range(n):
	if y1[i][0] is not y2[i][0]:
		has_intersection = True

if has_intersection:
	print("YES")
else:
	print("NO")