# arr = list(map(int,input().split()))
# for i in range(1,len(arr)):
#     k=arr[i]
#     j=i-1
#     while j>=0 and arr[j]>k:
#         arr[j+1]=arr[j]
#         j=j-1

#     arr[j+1]=k

# print(arr)


# l=list(map(int,input().split()))
# for i in range(len(l)):
#     mid_idx=i 
#     for j in range(i+1,len(l)):
#         if l[mid_idx]>l[j]:
#             mid_idx=j 

#     l[i],l[mid_idx]=l[mid_idx],l[i]

# print(l)


# def merge(l,p,r):
#     if p<r:
#         q=(p+(r-1))//2

#         merge(l,p,q)
#         merge(l,q+1,r)
    


# l=list(map(int,input().split()))
# merge(l,0,len(l)-1)
# for i in range(len(l)):
#     print(l[i]





n,k=map(int,input().split())
l=list(map(int,input().split()))

a=l.index(min(l))

m=l[a]+1
c=0
f=k-1
for i in range(n):
	if l[f]==l[a]:
		d=f
		break
	f=(f-1)%n
for i in range(n):
	l[d]-=m
	c+=m 

	if d==k-1:
		m-=1

	d=(d+1)%n


l[a]=c-1
print(*l)










