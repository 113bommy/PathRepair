l, inp,maxseq,currseq = int(input()), [0]+list(map(int, input().split(" ")))+[1001, 5000],0,[]
for i in range(l+2):
	if inp[i]+1 == inp[i+1]: currseq.append(inp[i])
	else: maxseq,currseq = max(maxseq, len(currseq)),[]
print(max(maxseq-1, 0))