#!/usr/bin/python3
"B. Students and Shoelaces"
"Codeforces Beta Round #94 (Div. 2 Only)"
# n,m=map(int,input().split())
# d={}
# for i in range(m):
#     z,x=map(int,input().split())
#     d.setdefault(z,[])
#     d.setdefault(x,[])
#     d[z].append(x)
#     d[x].append(z)

# k=0    
# while True:
#     f=0
#     t=[False]*(n+1)
#     # print(d)
#     for i in range(1,n+1):
#         if d.get(i) and len(d[i])==1 and t[i]==False:
#             # print(i,d[i])
#             asdf=d[i].pop(0)
#             d[asdf].remove(i)
#             t[asdf]=True
#             t[i]=True
#             f=1
#     if f==0:
#         break
#     k+=1
# print(k)            
"Codeforces Round #272 (Div. 2)"
"B. Dreamoon and WiFi"
# q=0
# for i in input():
#     if i=='+':
#         q+=1
#     else:
#         q-=1
# a=k=0
# for i in input():
#     if i=='+':
#         k+=1
#     elif i=='-':
#         k-=1
#     else:
#         a+=1

# arr=[k]
# for i in range(a):
#     arr.extend(arr)
#     for j in range(int(len(arr)/2)):
#         arr[j]+=1
#     for j in range(int(len(arr)/2),len(arr)):
#         arr[j]-=1
# hit=arr.count(q)
# print(hit/2**a)
"Codeforces Round #268 (Div. 2)"
"B. Chat Online"
# p,q,l,r=map(int,input().split())
# z=[]
# x=[]
# for i in range(p):
#     a,b=map(int,input().split())
#     z.append([a,b])
# for i in range(q):
#     c,d=map(int,input().split())
#     x.append([c,d])
# s=[i for i in range(l,r+1)]
# s=set(s)
# lr=set()
# # print(z,x)
# for j in z:
#     for i in x:
#         add=[]
#         if i[0]>j[1]:
#             continue
#         elif i[0]>=j[0]:
#             add.extend([t for t in range(0,j[1]-i[0]+1)])
#         elif i[1]>=j[0]:
#             add.extend([t for t in range(0,j[1]-i[0]+1)])
#         elif i[1]<j[0]:
#             add.extend([t for t in range(j[0]-i[1],j[1]-i[0]+1)])
#         m=set(add)
#         # print(add,m,i,j)
#         lr=lr.union(m)
# # print(s,lr)        
# print(len(s.intersection(lr)))
"Codeforces Round #132 (Div. 2)"
"B. Olympic Medal"
# from math import sqrt
# x=list(map(int,input().split()))
# y=list(map(int,input().split()))
# z=list(map(int,input().split()))
# r1=max(x[1:])
# p1=max(y[1:])
# p2=min(z[1:])
# a,b=map(int,input().split())
# bp1=b*p1
# ap2=a*p2
# r2=r1*sqrt(bp1/(bp1+ap2))
# print(r2)
"Codeforces Round #371 (Div. 2)"
"B. Filya and Homework"
# n=int(input())
# a=list(map(int,input().split()))
# s=list(set(a))
# if (len(s)==3 and sum(s)%3==0 and sum(s)/3 in s) or len(s)<3:
#     print("YES")
# else:
#     print("NO")    
"Codeforces Round #234 (Div. 2)"
"B. Inna and New Matrix of Candies"
# n,m=map(int,input().split())
# r=[]
# for i in range(n):
#     a=list(input())
#     fg=0
#     d=0
#     for j in range(m):
#         if a[j]=='G':
#             fg=j+1
#         elif fg==0 and a[j]=='S':
#             fg=-1
#             break
#         elif fg!=0 and a[j]=='S':
#             d+=1
#             break
#         elif fg!=0:
#             d+=1        
#     if fg==-1:
#         print(-1)
#         break
#     r.append(d)
# # print(r)
# if fg!=-1:
#     print(len(set(r)))    
"Codeforces Round #108 (Div. 2)"
"B. Steps"    
n,m=map(int,input().split())
x,y=map(int,input().split())
k=int(input())
d=0
for i in range(k):
    a,b=map(int,input().split())
    na1=na2=nb1=nb2=0
    if a!=0:
        na1=int((n-x)/a)
        na2=int((1-x)/a)
    if b!=0:
        nb1=int((m-y)/b)
        nb2=int((1-y)/b)
    na=max(na1,na2)
    nb=max(nb1,nb2)
    if a==0 or b==0:
        na+=nb
        nb=na
    z=min(na,nb)
    d+=z
    x+=z*a
    y+=z*b
    print(na1,na2,nb1,nb2)
    print(d,x,y)
print(d)



