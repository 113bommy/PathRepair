from sys import stdin, stdout
import math

def main():
	line = stdin.readline()
	n = int(line.split()[0])
	k = int(line.split()[1])
	line = stdin.readline()
	arr = [int(x) for x in line.split()]
	zero = []
	j = -1
	start = 0
	zeros=0
	ones=0
	max_len=0
	for i in range(n):
		if(arr[i] == 1):
			ones += 1
		else:
			zero.append(i)
			if(zeros < k):
				ones+=1
				zeros+=1
			else:
				j += 1
				ones = i-zero[j]
		# max_len = max(max_len, ones)
		if(ones > max_len):
			start = i+1-ones
			max_len = ones
		# print('i: ',i, 'ones: ',ones,'zeros: ',zeros,'last_zero: ',last_zero)
	print(str(max_len))
	for i in range(n):
		if(i >= start and i <= start+max_len):
			stdout.write(str("1 "))
		else:
			stdout.write(str(arr[i])+" ")

if __name__ == '__main__':
	main()