a =input().split(" ")
s = int(a[0])
v1 = int(a[1])
v2 = int(a[2])
t1 = int(a[3])
t2 = int(a[4])

first_time = s * v1 + 2*t1
second_time = s * v2 + 2*t2

if first_time < second_time: 
	print("First")
elif second_time < first_time:
	print("Second")
else: 
	print("Freindship")