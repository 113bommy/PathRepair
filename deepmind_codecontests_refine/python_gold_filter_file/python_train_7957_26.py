n=input()
k=int(input())
l=list(map(int,input().split()))
m=max(l)
x=0
for i in range (0,len(n)):
    x+=l[ord(n[i])-97]*(i+1)
    # print(x)
for j in range(len(n)+1,(len(n)+k)+1):
    x+=m*j
print(x)