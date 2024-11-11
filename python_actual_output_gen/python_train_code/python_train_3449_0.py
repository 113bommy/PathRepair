n = int(input())

cookies = [int(i) for i in input().split()]

if sum(cookies) % 2 == 0: #even
	tf = [i % 2 == 0 for i in cookies]
else: #odd
	tf = [i % 2 == 0 for i in cookies]
	
print(sum(tf))