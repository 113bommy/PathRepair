n,k=map(int,input().split())
s=input()
di={}
for i in range(k):
    if(chr(65+i) not in di):
        di[chr(65+i)]=0
for i in s:
    if i in di:
        di[i]+=1
l=list(di.keys())
x=min(l)*k
print(x)