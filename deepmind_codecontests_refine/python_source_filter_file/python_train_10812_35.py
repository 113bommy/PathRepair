s=input()
n=len(s)
a=[ord(i)-ord('a') for i in s]
k=int(input())
for i in range(n):
    if a[i]+k>=26 and a[i]>0:
        k-=26-a[i]
        a[i]=0
k%=26
print(a)
a[-1]+=k
a=[chr(i + ord('a')) for i in a]
print(*a,sep="")