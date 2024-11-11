if __name__ == '__main__':
	n = int(input().strip(" "))
	server_one = (0,0)
	server_two = (0,0)
	for _ in range(n):
		t,x,y = tuple(map(int,input().strip(" ").split(" ")))
		if t == 1:
			server_one = (server_one[0]+x,server_one[1]+y)
		else:
			server_two = (server_one[0]+x,server_two[1]+y)
	if server_one[0]>=server_one[1]:
		print("LIVE")
	else:
		print("DEAD")
	if server_two[0]>=server_two[1]:
		print("LIVE")
	else:
		print("DEAD")
