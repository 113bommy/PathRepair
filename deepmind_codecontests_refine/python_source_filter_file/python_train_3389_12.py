import sys
def I():
	return((list(map(int,input().split()))))


n,m=I()
# print(n)
for i in range(n):
	x=input()
	if "C" in x or "M" in x or "Y" in x:
		print("#Color")
		# break;
		sys.exit()
print("##Black&White")


