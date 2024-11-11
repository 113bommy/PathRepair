import sys
import heapq

#comment these out later
#sys.stdin = open("in.in", "r")
#sys.stdout = open("out.out", "w")

input = sys.stdin.readline

def main():
	pq = []

	n = int(input())

	g = [[] for _ in range(n)]

	big = [0]*n
	bigs = 0

	for i in range(n):
		ar = list(map(int, input().split()))
		g[i] = ar[1:]
		big[i] = ar[0]
		bigs += ar[-1]

	m = int(input())

	banned = set()

	for _ in range(m):
		banned.add(tuple(map(int, input().split())))

	visited = set()

	#print(banned)

	pq.append((-bigs, tuple(big)))

	for x in range(m+1):
		cand = heapq.heappop(pq)

		tup = cand[1]

		if tup not in banned:
			print(* tup)
			sys.exit()

		ltup = list(tup)
		stup = -cand[0]

		#print(cand, ltup, stup)

		for i in range(n):
			if ltup[i] > 1:
				ltup[i] -= 1
				newtup = tuple(ltup)
				if newtup in visited:
					pass
				else:
					visited.add(newtup)
					newstup = stup + g[i][ltup[i]-1] - g[i][ltup[i]]
					#print(ltup, newstup)
					heapq.heappush(pq, (-newstup, newtup))

				ltup[i] += 1




main()