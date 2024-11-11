import sys
import math
input = sys.stdin.buffer.readline


n,k = map(int,input().split())

m = list(map(int,input().split()))
c = list(map(int,input().split()))

m.sort()



out = []
pointer = []


minI = -1
maxI = -1
for i in range(n-1, -1,-1):
	mm = m[i]

	if m[-1] == 199791 and n-i<10:
		print(minI,m[i])
	if len(out)==0:
		out.append([mm])
		pointer.append(0)
		minI = 0
		maxI = 0
		continue


	if c[mm-1] - len(out[minI])>0:
		out[minI].append(mm)

		if len(out[minI])>len(out[pointer[minI]]):
			tmp = pointer[minI]
			pointer[maxI] = minI
			pointer[minI] = minI
			maxI = minI
			minI = tmp 

	else:
		out.append([mm])
		pointer.append(minI)
		minI = len(out)-1
	# if m[-1] == 199791 and n-i<10:
	# 	print(minI,pointer)

# if m[-1]==199791:
# 	print(len(out))
# 	for i in range(len(out)):
# 		print(len(out[i]),end=" ")
# 		#for j in out[i]:
# 		print(out[i][:5],end = " ")
# 		print()
# else:
print(len(out))
for i in range(len(out)):
	print(len(out[i]),end=" ")
	for j in out[i]:
		print(j,end = " ")
	print()