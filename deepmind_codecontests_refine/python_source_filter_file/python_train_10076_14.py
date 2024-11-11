N=int(input())
p=list(map(int, input().split()))

cnt=0
min=p[0]
for i in range(N):
	if p[i]<=min:
		min=p[i]
        cnt+=1
	
print(cnt)