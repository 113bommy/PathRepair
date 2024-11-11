n=input()
k=int(input())
l=list(map(int,input().split()))
s=0
for i in range(len(n)):
    s=s+(i+1)*l[(ord(n[i])-97)]
m=max(l)
for j in range(i+i,k+i+2):
    s=s+(j)*m
    
print(s)