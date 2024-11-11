numParticipants = int(input(""))
scores = [int(x) for x in input("").split(" ")]

prevScore = 0
subsets = 0
for score in sorted(scores):
    if score != prevScore:
        subsets += 1
    prevScore = score
print(subsets)