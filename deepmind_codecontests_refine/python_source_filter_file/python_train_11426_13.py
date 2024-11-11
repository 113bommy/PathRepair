def antipalindrome(A):
	front=0
	end=len(A)-1
	duplicates=1
	temp=A[front]
	while(front<end):
		if temp!=A[front]:
			duplicates=0
		if A[front]!=A[end]:
			return len(A)
		temp=A[front]
		front=front+1
		end=end-1
	if duplicates:
		return 0
	else:
		return len(A)-1
A=list(input())
print(antipalindrome(A))
	