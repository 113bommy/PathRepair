'''
INPUT SHORTCUTS
N, K = map(int,input().split())
N ,A,B = map(int,input().split())
string = str(input())
arr = list(map(int,input().split()))
N = int(input())
'''



def main():
	N = int(input())
	parent = [-1,-1]
	parent.extend(list(map(int,input().split())))
	color = [-1]
	color.extend(list(map(int,input().split())))
	cnt = 0
	for i in range(2,len(color)):
		print(color[parent[i]],parent[i],color[i])
		if color[parent[i]]!=color[i]:
			cnt+=1
	print(cnt+1)

main()