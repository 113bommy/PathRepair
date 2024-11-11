def fun(ss,arr,i):
	if i>len(arr)-1:
		if ss%360==0:
			print("YES")
			exit()
		return
	else:
		fun(ss-arr[i],arr,i+1)
		fun(ss+arr[i],arr,i+1)
n=int(input())
arr=[]
for i in range(n):
	x=int(input())
	arr.append(x)
ss=0
fun(ss,arr,0)
# print(ss)
print("NO")