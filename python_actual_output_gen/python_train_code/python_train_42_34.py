n = int(input())	
vote= list(map(int,input().split()))
votes,i =sum(vote)*n,max(vote)
while True:
	if votes<i*n-votes:
		print(i)
		break
	i+=1
