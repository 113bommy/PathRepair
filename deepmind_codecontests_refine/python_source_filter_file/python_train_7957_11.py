n=input()
k=int(input())
a="abcdefghijklmnopqrstuvwxyz"
b=list(map(int,input().split()))
count=0
for i in range(len(n)):
    c=a.index(n[i])
    count+=(c+1)*(b[c])
c=max(b)
for i in range(len(n)+1,len(n)+k+1):
    count+=i*c
print(count)