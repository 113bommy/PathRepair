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
	arr = list(map(int,input().split()))
	start = 1
	flag = True
	index = -1
	for i in range(len(arr)):
		if arr[i]-start>15:
			flag = False
			index = i
			break
		start= arr[i]
	# print(flag)
	# print(index)
	if flag:
		if 90-arr[-1]>=15:
			print(arr[-1]+15)
		else:
			print(90)
	else:
		if index-1>=0:
			print(arr[index-1]+15) 
		else:
			print(15)
main()