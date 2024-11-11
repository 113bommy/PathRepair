from math import *

if __name__=="__main__":
	k,d,t=map(int,input().split())
	# print(k,d,t)

	per=ceil(k/d)*d
	fire=k if d >=k else per-per%k
	warm=(per-fire)/2

	print(per,fire,warm)

	ans=t//(fire+warm)*per

	remain=t-t//(fire+warm)*(fire+warm)

	if remain<=fire:
		ans+=remain
	else:
		ans+=fire
		remain-=fire
		ans+=remain*2
	print(ans)