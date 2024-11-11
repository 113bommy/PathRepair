games = int(input())
matches = input().strip()
val = matches.count('A') << 1
if val > games:
	print("Anton")
elif val == games:
	print("Friendship")
else:
	print("Danik")