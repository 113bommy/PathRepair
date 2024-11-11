
def findSequence(N, arrayF, M, arrayB):
	positions = [0]*N
	amb = False
	
	for i in range(N):
		val = arrayF[i]
		if val < 1 or val > N:
			return ("Impossible",[])
		pos = positions[val-1]
		if pos > 0:
			positions[val-1] = -1
		else:
			positions[val-1] = i + 1

	output = [0]*M
	for j in range(M):
		key = arrayB[j]
		if key < 1 or key > N:
			return ("Impossible",[])
		pos = positions[key - 1]
		if pos == -1:
			amb = True
		elif pos == 0:
			return ("Impossible",[])
		else:
			output[j] = pos

	if amb:
		return ("Ambiguity",[])
	
	return ("Possible", output)

if __name__=="__main__":
	n, m = input().split()
	n, m = int(n), int(m)
	arrayF = input().split()
	arrayF = [ int(x) for x in arrayF ]
	arrayB = input().split()
	arrayB = [ int(x) for x in arrayB ]
	status, output = findSequence(n, arrayF, m, arrayB)
	print(status)
	if status == "Possible":
		print(' '.join([ str(x) for x in output ]))
	