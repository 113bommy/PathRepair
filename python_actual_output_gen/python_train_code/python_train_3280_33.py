n = int(input())
t = list(map(int,input().split()))

if t.count(min(t))==2:
	print('Still Rozdil')
else:
	print(t.index(min(t))+1)