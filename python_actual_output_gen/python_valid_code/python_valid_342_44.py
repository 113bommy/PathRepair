n,c,k = (int(i) for i in input().split())
t = [int(input()) for i in range(n)]
t.sort()
num,num2,answer = t[0]+k,0,1
for i in range(n):
	num2 += 1
	if t[i]>num or num2>c:
		num,num2=t[i]+k,0
		answer+=1
print(answer)