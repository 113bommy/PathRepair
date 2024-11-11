str1=input()

dic={'R':0,'L':0,'U':0,'D':0}
l=len(str1)
if(l%2!=0):
	print(-1)
	exit()


for i in str1:
	dic[i]+=1

s=abs(dic['R']-dic['L'])+abs(dic['U']-dic['D'])//2

print(s)
