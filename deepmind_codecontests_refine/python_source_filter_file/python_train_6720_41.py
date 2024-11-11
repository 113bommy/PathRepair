from sys import stdin, stdout

def func():
	n = int(input())
	scores = []
	for i in range(n):
		scores.append([int(x) for x in stdin.readline().rstrip().split()])
	m=0
	for score in scores:
		if score[0]>score[1] : m+=1
		if score[0]<score[1] : m-=1
	if m>0 : 
		print ("Misha\n")
	elif m<0 : 
		print ("Chris\n")
	else : 
		print ("Friendship is magic!^^\n")


if __name__ == '__main__':
	func()
