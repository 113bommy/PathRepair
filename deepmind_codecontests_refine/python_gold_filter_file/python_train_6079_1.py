s=input()
n=int(input())
a=[0]
for i in range(len(s)-1):
    a+=[a[-1]+(s[i]==s[i+1])]
d=''
for i in range(n):
    l,r=map(int,input().split())
    d+=str(a[r-1]-a[l-1])+'\n'
print(d)