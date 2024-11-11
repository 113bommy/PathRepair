n,A,B = map(int,input().split())
s = [int(i) for i in input().split()]
S = sum(s)
a = s.pop(0)
s.sort(reverse=True)
cnt = 0

for i in range(n-1):
	if (A*a/S)>B:
		break
	else:
		S-=s[i]
		cnt+=1
print(cnt)