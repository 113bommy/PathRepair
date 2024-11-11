n=int(input())
*l,=map(int,input().split())
a=b=i=0
j=n-1
while i<j:
    if a<b:a+=l[i];i+=1
    else:b+=l[j];j-=1
print(i,n-i)