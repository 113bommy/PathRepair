def getHighAns(a, low, high):
	count = 1
	ans = ''
	ans += 'R'
	last = a[high]
	high -= 1
	while(low <= high):
		if(last < a[high]):
			count += 1
			ans += 'R'
			last = a[high]
			high -= 1
		else:
			break
	return count, ans
def getLowAns(a, low, high):
	count = 1
	ans = ''
	ans += 'L'
	last = a[low]
	low += 1
	while(low <= high):
		if(last < a[low]):
			count += 1
			ans += 'L'
			last = a[low]
			low += 1
		else:
			break
	return count, ans
n = int(input())
a = list(map(int, input().split()))
low = 0
high = n-1
last = 0
count = 1
ans = ""
if(a[low] < a[high]):
	last = a[low]
	ans += 'L'
	low += 1
else:
	last = a[high]
	ans += 'R'
	high -= 1
while(low <= high):
	if(a[high] == a[low] and last < a[low]):
		ch, ah = getHighAns(a, low, high)
		cl, al = getLowAns(a, low, high)
		if(ch > cl):
			count += ch
			ans += ah
			break
		else:
			count += cl
			ans += al
			break
	elif(last < a[low] < a[high]):
		last = a[low]
		ans += 'L'
		count += 1
		low += 1
	elif(last < a[high] < a[low]):
		last = a[high]
		ans += 'R'
		count += 1
		high -= 1
	elif(last < a[low]):
		last = a[low]
		ans += 'L'
		count += 1
		low += 1
	elif(last < a[high]):
		last = a[high]
		ans += 'R'
		count += 1
		high -= 1
	else:
		break
print(count)
print(ans)