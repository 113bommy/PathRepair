n = int(input())
s = [int(i) for i in input().split()]
x,y = map(int,input().split())
ans = 0

for i in range(1,n):
	if x<=sum(s[0::i])<=y and x<=sum(s[i::])<=y:
		ans = i+1
		break

print(ans)

