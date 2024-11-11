a,b,c=map(int,input().split())
n=list(input())
n=n[::-1]
p=min(c,b)
l=10000000000
i=0
w=0
while i<a:
    if n[i]=="0":
        w+=1
        while n[i]=="0":
            i+=1
            if i==a:
                break
    else:
        i+=1
if len(set(n))==1 and list(set(n))[0]=="1":
    l=0
print(min(l,p*(w-1)+c))