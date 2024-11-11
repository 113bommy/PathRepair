_ = int(input())
record = input()

if(record.count("A") > record.count("D") ):
	print("Anton")
elif(record.count("D") > record.count("A") ):
	print("Danik")
else:
	print("Friendship")