# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
# D={'Power':'purple','Time':'green','Space':'blue','Soul':'orange','Reality':'red','Mind':'yellow'}
# T=int(input())
# L=[]
# for i in range(T):
#  	L.append(input())
# X=list(D.values())
# Y=list(set(X)-set(L))
# K=dict([(value,key) for key,value in D.items()])
# print(len(Y))
# # for i in range(len(Y)):
# 	print(K.get(Y[i])
# m,n=map(int,(input().split()))
# L=list(map(int,input().split()))
# F=list(map(int,input().split()))
# for i in range(m):
# 	for j in range(n):
# 		if L[i]==F[j]:
# 			print(L[i],end=" ")
T=int(input())
L=input()
ones=L.count('1')
zeroes=T-ones;
count=0
L=list(map(int,L.split()))
for i in range(T):
	if L[i]==1:
		count+=1
	if count==ones:
		print(i)
		break
	if T-count==zeroes:
		print(i)
		break




# for i in range(len(L)):
# # 	FLAG=
# # 	for j in range(i,len(L)):
# # 		if L[j]!=L[i]:
# # 			FLAG=1
# # 	if FLAG==0:
# # 		break
# # print(i)
