n,m = map(int,input().split())
al = list(map(int,input().split()))
bl = list(map(int,input().split()))
# a = 0
# for i in bl:
# 	for j in al:
# 		if (i+j)%2==1:
# 			a+=1
# 			al.remove(j)
# 			break
# print(a)
oa = len(list(filter(lambda x:x%2==1 , al)))
ob = len(list(filter(lambda x:x%2==1 , bl)))
# print(oa,ob)
print(min(oa,(n-oa))+min(ob,(m-ob)))
