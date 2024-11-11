x,y = map(int, input().split())

ans = abs(abs(x)-abs(y))
if x > y and abs(x) != abs(y) and x*y > 0:
	ans+=2
elif x*y < 0 or (x>y and x==0) or (x>y and y==0):
	ans+=1a

print(ans)
