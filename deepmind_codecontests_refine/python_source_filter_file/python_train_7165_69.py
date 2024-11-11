n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
count=0
for a,b in zip(A,B):
   if a>b:count -=a-b
   elif b>a:count +=(b-a)/2

print("Yes" if count>0 else "No")