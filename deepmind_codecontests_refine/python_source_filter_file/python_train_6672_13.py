def main():
	n=int(input())
	cur_max=int(max(input().split()))
	for i in range(1,n):
		w,h=map(int,input().split())
		maxi=max(w,h)
		mini=min(w,h)
		if cur_max>=maxi:
			cur_max=maxi
		elif cur_max>=mini:
			cur_max=mini
		else:
			print('NO')
			return

	print('YES')

main()