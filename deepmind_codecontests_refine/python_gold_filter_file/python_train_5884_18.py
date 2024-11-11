import math

data = input()

start = int(data[:data.find(" ")])
end = int(data[data.find(" ")+1:])
output = 0

length_start = int(start.bit_length())
length_end = int(end.bit_length())
length_diff = int(length_end - length_start)
maximum = int(math.pow(2,length_end))-1
#print(maximum)
#print(length_diff)

for j in range(1,length_diff+2):
	#print (bin(int(maximum)))
	#print (bin(int(math.pow(2,length_end-j))))
	for i in range(length_end-j):

		diff = maximum - int(math.pow(2,i))
		
		if ((diff >= start) & (diff <= end)):
			output += 1	
			#print (bin(diff))
	maximum = maximum - int(math.pow(2,length_end-j))
#output -= 
print(output)