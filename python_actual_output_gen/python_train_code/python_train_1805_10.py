a = int(input())
b = list(map(int,input().split()))
q,w=1,0
for j in range(a-1):
	if b[j]*2>=b[j+1]:q+=1
	else:q=1
	w = max(q,w)
print(w)