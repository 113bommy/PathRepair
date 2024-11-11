f=lambda:map(int,input().split())
n=int(input())
s='1 '*n
for i in range(1,n//2):
    s=s.replace(str(i)+' '+str(i),str(i+1))
print(s)