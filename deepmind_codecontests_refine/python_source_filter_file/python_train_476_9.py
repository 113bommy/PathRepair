# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
# #print(hex(a))
# #print(bin(a))
# #print(oct(a))
#print(a|b)
#print(a&b)
#print(a^b)
s,v1,v2,t1,t2=map(int,input().split())
first=v1*s+2*t1
second=v2*s+2*t2
if first>second:
	print("First")
else:
	if first<second:
		print("Second")
	else:
		print("Friendship")