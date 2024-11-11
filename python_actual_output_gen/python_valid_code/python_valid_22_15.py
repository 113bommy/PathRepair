n = int(input())
l = list(map(int,input().split()))
c = sum(l[0:n:3])
bi = sum(l[1:n:3])
ba = sum(l[2:n:3])
if max(c,bi,ba) == c:
	print("Chest")
elif max(c,bi,ba) == bi:
	print("Biceps")
else:
	print("Back")