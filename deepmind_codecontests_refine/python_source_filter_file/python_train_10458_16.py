# ===============================
# (c) MidAndFeed aka ASilentVoice
# ===============================
import math, fractions
# ===============================
q = [int(x) for x in input().split()]
sq = set(q)
if not(any(q.count(x) >= 4 for x in sq)):
	print("Alien")
else:
	if len(sq) == 3:
		print("Bear")
	elif len(sq) == 1:
		print("Bear")
	else:
		if any(q.count(x) > 4 for x in sq):
			print("Bear")
		else:
			print("Elephant")