from sys import stdin
input=stdin.readline
for _ in range(int(input())):
	input();d=[0]*3
	for i in map(int,input().split()):d[i%3]+=1
	print(d[0]+min(d[1:])+(d[1]-min(d[1:]))//3)