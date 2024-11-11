#codeforces_959B
line = [int(e) for e in input().split(" ")]
n = line[0]; k = line[1];
line = input().split(" ")
line2 = [int(e) for e in input().split(" ")]
score = {}
for j in range(n):
	score[line[j]] = line2[j]
for j in range(k):
	line2 = [int(e)-1 for e in input().split(" ")]
	line2.remove(line2[0])
	minscore = score[line[line2[0]]];
	for e in line2:
		minscore = min(minscore,score[line[e]])
	for e in line2:
		score[line[e]] = minscore
print(sum([score[e] for e in input().split(" ")]))
