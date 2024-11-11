input()
l = list(map(int,input().split()))
k = min(l)
if l.count(k)>1:
	print("Still Rozdill")
else:
	print(l.index(k)+1)