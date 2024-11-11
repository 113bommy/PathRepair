n = int(input())
guardp_ = [list(map(int,input().split())),list(map(int,input().split())),list(map(int,input().split())),list(map(int,input().split()))]
for i in range(4):
	if guardp_[i][0] + guardp_[i][3] <= n:
		print(i+1,guardp_[i][0],n-guardp_[i][0])
		exit()
	elif guardp_[i][1] + guardp_[i][2] <= n:
		print(i+1,guardp_[i][1],n-guardp_[i][1])
		exit()
	elif guardp_[i][0] + guardp_[i][2] <= n:
		print(i+1,guardp_[i][0],n-guardp_[i][0])
		exit()
	elif guardp_[i][1] + guardp_[i][3] <= n:
		print(i+1,guardp_[i][0],n-guardp_[i][0])
		exit()
print(-1)
