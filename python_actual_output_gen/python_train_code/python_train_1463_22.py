n=int(input())
m=int(input())
l=[int(input()) for i in range(n)]
l.sort(reverse=True)
print(l)
count=0
sum=0
for i in range(len(l)):
		if m <= sum:
			break
		sum+=l[i]
		count+=1
print(count)