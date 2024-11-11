from collections import Counter
def f(a):
	l=0
	ans=0
	# a=sorted(a,reverse=True)
	t=[]
	tc=[0,0,0,0,0]
	for i in a:
		cnt=Counter(i)
		tr=[0,0,0,0,0]
		for ltr in cnt:
			tr[ord(ltr)-ord("a")]+=cnt[ltr]
			tc[ord(ltr)-ord("a")]+=cnt[ltr]
		t.append(tr)
	total=sum(tc)
	for chr in range(0,5):
		temp=total-tc[chr]
		tempchr=tc[chr]
		tans=len(a)
		t=sorted(t,key=lambda s:s[chr])
		t=sorted(t,key=lambda s:temp-(sum(s)-s[chr]))
		# print(t,chr)
		for  lst in t:
			# print(tempchr,temp,chr)
			if tempchr>temp:
				ans=max(ans,tans)
				break
			else:
				tempchr-=lst[chr]
				temp=(temp-sum(lst))+lst[chr]
				tans-=1
	return ans

	ans=0

for _ in range(int(input())):
	n=int(input())
	q=[]
	for i in range(n):
		q.append(input())
	print(f(q))