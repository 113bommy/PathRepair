N = 10000
Z = 26

#别用这玩意儿: trie = [[0] * Z] * N 巨坑！https://www.cnblogs.com/PyLearn/p/7795552.html

trie = [[0 for i in range(Z)] for j in range(N)]
n = 0
k = 0
nodeNum = 0

def insertNode():
	u = 0
	string = input()
	global nodeNum
	
	for i in range(len(string)):
		c = ord(string[i]) - ord('a')
		if trie[u][c] == 0:
			nodeNum += 1
			trie[u][c] = nodeNum	
			u = trie[u][c]
		# print(u)
	
stateWin = [False for i in range(N)]	
stateLose = [False for i in range(N)]	
	
def dfs(u):
	leaf = True
	for c in range(Z):
		if (trie[u][c]) != 0:
			leaf = False
			dfs(trie[u][c])
			stateWin[u] |= (not(stateWin[trie[u][c]]))
			stateLose[u] |= (not(stateLose[trie[u][c]]))
	if leaf == True:
		stateWin[u] = False
		stateLose[u] = True

n,k = map(int,input().split())

for i in range(n):
	insertNode()

dfs(0)


# print(stateWin[0])
# print(stateLose[0])

if (stateWin[0] and (stateLose[0] or (k % 2 == 1) )):
	print("First")
else:
	print("Second")