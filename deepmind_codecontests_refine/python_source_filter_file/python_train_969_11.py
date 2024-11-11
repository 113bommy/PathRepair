n = int(input())
results = list(map(int, input().split()))

record_high = 0
record_low = results[0]
count = 0

for i in results[1:]:
	
	if i > record_high:
		count +=1
		record_high = i
	
	elif i < record_low:
		count +=1 
		record_low = i
	

print(count)