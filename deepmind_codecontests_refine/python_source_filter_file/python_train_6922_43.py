a = [ int(b) for b in input().split(" ") ]
e,c = [ int(d) for d in input().split(" ") ]
h = [ int(f) for f in input().split(" ") ]
g = sorted([ int(h) for h in input().split(" ") ], reverse=True)


found_in_first_array = False
found_in_second_array = False

if len(h) > e:
	found_in_first_array = True

count = 0
for i in range(len(g)):
	if g[i] > h[e-1]:
		count = count + 1

if count >= c:
	found_in_second_array = True


if found_in_first_array and found_in_second_array:
	print("YES")
else:
	print("NO")
