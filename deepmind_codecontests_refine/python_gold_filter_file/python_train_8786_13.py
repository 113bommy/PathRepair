n = int(input())
s = [int(i) for i in input().split()]
x,y = map(int,input().split())
ans = 0

for j in range(1,n):
	if x<=sum(s[0:j])<=y and x<=sum(s[j::])<=y:
		ans = j+1
		break

print(ans)

