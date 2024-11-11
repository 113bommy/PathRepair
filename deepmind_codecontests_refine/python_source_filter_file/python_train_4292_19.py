
#create a string in which no two same  char comes together.
# assumption only small albhabetical letters used
#input format: just enter the string without any space
import sys
import math
input = sys.stdin.readline
 
############ ---- Input Functions ---- #######Start#####
def inp():
	return(int(input()))
def inlt():
	return(list(map(int,input().split())))
def insr():
	s = input()
	return(list(s[:len(s) - 1]))
def invr():
	return(map(int,input().split()))
 ############ ---- Input Functions ---- #######End#####   
def pr_list(a):
	print(*a, sep=" ")
def main():
	tests = inp()
	for test in range(tests):
		n =  inp()
		n1 = math.sqrt(n) + 2
		out = []
		flag = 1
		i = 2
		while(i<n1  and len(out)< 3):
			if n %i == 0 :
				n = int(n/i)
				n1 = math.sqrt(n) + 2
				if i not in out:
					out.append(i)
				if len(out) == 2 and n not in out:
					out.append(n)
					break
			i = i + 1
		if len(out) == 3:
			print("YES")
			pr_list(out)
		else:
			print("NO")

				






		



	return




	#time o(2n) space o(26*2)

	#sorted(hashm.items(), key=lambda item: item[1])

if __name__== "__main__":
  main()