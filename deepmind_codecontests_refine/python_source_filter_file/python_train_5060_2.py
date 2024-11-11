import sys

#comment these out later
#sys.stdin = open("in.in", "r")
#sys.stdout = open("out.out", "w")


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

k = inp[ii]; ii += 1
n = inp[ii]; ii += 1

marks = inp[ii:ii+k]; ii += k
scores = inp[ii:ii+n]

pre = [0]

for x in marks:
	pre.append(pre[-1] + x)

ans = set()

for b in pre[1:]:
	ans.add(b+scores[0])

for a in scores[1:]:
	scset = set()
	for b in pre[1:]:
		scset.add(a+b)
	ans = ans&scset

print(len(ans))