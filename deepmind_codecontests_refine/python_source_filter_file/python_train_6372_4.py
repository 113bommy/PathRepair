def mapit():
	temp=list(map(int,input().split()))
 
	return temp



def solution():
	n,k=mapit()
	arr=input()
	available=set(list(map(str,input().split())))
	if len(available)==26:
		ans=n
		ans*=(n+1)
		ans=ans//2
		print(ans)

	idx=0
	ans=0
	while idx<n:
		cnt=0
		if arr[idx] in available:
			while idx<n and arr[idx] in available:
				cnt+=1
				idx+=1
		ans=ans+((cnt*(cnt+1))//2)
		idx+=1
	print(ans)
	return
	


# t=int(input())
 
# while t:
# 	t-=1
solution()
