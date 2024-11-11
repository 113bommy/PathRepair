#設定
import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10**7)

#ライブラリインポート
from collections import defaultdict

#入力受け取り
def getlist():
	return list(map(int, input().split()))

class Graph(object):
	def __init__(self):
		self.graph = defaultdict(list)

	def __len__(self):
		return len(self.graph)

	def add_edge(self, a, b):
		self.graph[a].append(b)

	def get_nodes(self):
		return self.graph.keys()

def DFS(G, XOR, visit, node):
	for i in G.graph[node]:
		if visit[i] != "Yes":
			visit[i] = "Yes"
			DFS(G, XOR, visit, i)
			XOR[node] ^= XOR[i] + 1

#処理内容
def main():
	N = int(input())
	G = Graph()
	for i in range(N - 1):
		x, y = getlist()
		x -= 1
		y -= 1
		G.add_edge(x, y)
		G.add_edge(y, x)

	#計算
	XOR = [0] * N
	visit = ["No"] * N
	visit[0] = "Yes"
	DFS(G, XOR, visit, 0)
	if XOR[0] == 0:
		print("Bob")
	else:
		print("Alice")
	

if __name__ == '__main__':
	main()