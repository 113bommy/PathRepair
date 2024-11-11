def toInt(s):
	return (int(s[0]) * 10 + int(s[1]))*60 + int(s[3])*10 + int(s[4])	
def mx(a,b):
  	if a > b: 
  		return a
  	return b
def convert(val):
	return "%d%d:%d%d" % ((val//60%24//10),(val//60%24%10),(val%60//10),(val%60%10))
n = int(input())
arr=[]
for i in range(n):
	arr.append(input())
arr.sort()
ans = 0
for i in range(n-1):
	ans = mx(ans, (toInt(arr[i+1])-toInt(arr[i])-1+1440)%1440)
ans = mx(ans, (toInt(arr[n-1]) - toInt(arr[0]) - 1 + 1440)%1440);

print(convert(ans))		

