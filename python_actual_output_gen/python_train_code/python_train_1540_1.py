# import sys
# sys.stdin=open("input.in","r")
n,c=map(int,input().split())
p=list(map(int,input().split()))
t=list(map(int,input().split()))
#limak
sum1=0
sum2=0
for i in range(n):
	sum1+=t[i]
	w=p[i]-c*sum1
	sum2+=w
#raedwoosh
sum1=0
sum3=0
for j in range(n-1,-1,-1):
	sum1+=t[j]
	p[j]=max(0,p[j]-c*sum1)
	sum3+=p[j]
if(sum2>sum3):
	print("Limak")
elif(sum2==sum3):
	print("Tie")
else:
	print("Raedwoosh")