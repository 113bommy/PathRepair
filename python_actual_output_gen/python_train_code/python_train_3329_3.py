n=int(input())
s=str(input())
countsf=0
countfs=0
for i in range(n):
	if "SF" in s[i:i+2]:
		countsf+=1
	else:
		continue
for j in range(n):
	if "FS" in s[i:i+2]:
		countfs+=1
	else:
		continue
if countsf>countfs:
	print("YES")
else:
	print("NO")