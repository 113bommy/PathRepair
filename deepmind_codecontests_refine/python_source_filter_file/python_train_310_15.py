import math

def is_prime(n):
	for j in range(2,math.floor(math.sqrt(n))+1):
		if n%i==0:
			return False
	return True
 
cnt = 0
n=int(input())
for i in range(n):
    k=int(input())
    if is_prime(k):
        cnt+=1
print(cnt,end="")
