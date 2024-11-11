"Codeforces Round #631 (Div. 2)"
"A. Dreamoon and Ranking Collection"
# y=int(input())
# for i in range(y):
#     al=input().split()
#     m=list(map(int,al))
#     n=m[0]
#     x=m[1]
#     al=input().split()
#     m=list(map(int,al))
#     mas=n+x+4
#     li=[1]*mas
#     for j in m:
#         if j<mas:
#             li[j]=0
#     j=0
#     # print(li)
#     while x>0:
#         j+=1
#         # print(j,x,li)
#         if li[j]==1:
#             li[j]=0
#             x-=1
#     # print(j,x,li)        
#     for k in range(j,mas):
#         if li[k]==1:
#             break
#     print(k-1)        
"B. Dreamoon Likes Permutations"
# y=int(input())
# for i in range(y):
#     ans=[]
#     a=int(input())
#     al=input().split()
#     m=list(map(int,al))
#     l=[0]*a
#     mas=0
#     for j in range(a):
#         if mas<m[j]:
#             mas=m[j]
#         if l[m[j]]==1:
#             break
#         elif l[m[j]]==0:
#             l[m[j]]=1
#     s=sum(l)
#     # print(s,mas,l)
#     l=[0]*a
#     if s==mas:
#         mas1=0
#         for k in range(j,a):
#             if mas1<m[k]:
#                 mas1=m[k]
#             if l[m[k]]==1:
#                 break
#             elif l[m[k]]==0:
#                 l[m[k]]=1
#         s=sum(l)
#         # print(s,mas1,l)
#         if s==mas1 and mas+mas1==a:
#             # print(mas,mas1)
#             ans.append([mas,mas1])

#     m=m[::-1]
#     l=[0]*a
#     mas=0
#     for j in range(a):
#         if mas<m[j]:
#             mas=m[j]
#         if l[m[j]]==1:
#             break
#         elif l[m[j]]==0:
#             l[m[j]]=1
#     s=sum(l)
#     # print(s,mas,l)
#     l=[0]*a
#     if s==mas:
#         mas1=0
#         for k in range(j,a):
#             if mas1<m[k]:
#                 mas1=m[k]
#             if l[m[k]]==1:
#                 break
#             elif l[m[k]]==0:
#                 l[m[k]]=1
#         s=sum(l)
#         # print(s,mas1,l)
#         if s==mas1 and mas+mas1==a:
#             # print(mas1,mas)
#             if len(ans)==0:
#                 ans.append([mas1,mas])
#             elif len(ans)==1:
#                 if ans[0]!=[mas1,mas]:
#                     ans.append([mas1,mas])                 
#     print(len(ans))
#     for bv in ans:
#         print(bv[0],bv[1])
"Codeforces Round #619 (Div. 2)"
"A. Three Strings"
# y=int(input())
# for i in range(y):
#     a=list(input())
#     b=list(input())
#     c=list(input())
#     l=len(a)
#     f=1
#     for j in range(l):
#         if c[j]==a[j] or c[j]==b[j]:
#             pass
#         else:
#             f=0
#             break
#     if f==0:
#         print("NO")
#     else:
#         print("YES")      
"B. Motarack's Birthday"  
# y=int(input())
# for i in range(y):
#     n=int(input())
#     al=input().split()
#     m=list(map(int,al))
#     maxe=0
#     mine=int(1e9)
#     maxdiff=0
#     for j in range(n-1):
#         # print(maxdiff,maxe,mine)
#         if m[j]>maxe and m[j+1]==-1 and m[j]!=-1:
#             maxe=m[j]
#         if m[j]<mine and m[j+1]==-1 and m[j]!=-1:
#             mine=m[j]
#         if m[j+1]>maxe and m[j]==-1 and m[j+1]!=-1:
#             maxe=m[j+1]
#         if m[j+1]<mine and m[j]==-1 and m[j+1]!=-1:
#             mine=m[j+1]     
#         if j<n-1 and (m[j+1]!=-1 and m[j]!=-1):
#             if maxdiff<abs(m[j+1]-m[j]):
#                 maxdiff=abs(m[j+1]-m[j])      
#     # print(maxdiff,maxe,mine)
#     t=int((maxe+mine)/2)
#     t1=max(maxe-t,t-mine)
#     # print(t1,t)
#     print(max(maxdiff,t1),t)  
"C. Ayoub's function"
# def ayob(s):
#     d=[]
#     l=len(s)
#     for i in range(l):
#         if s[i]=="1":
#             d.append(i)
#     ans=0
#     # print(d,l)        
#     for i in range(l):
#         if s[i]=="0":
#             f=0
#             for j in d:
#                 if j>i:
#                     f=1
#                     break
#             if f==0:
#                 continue    
#             ans+=l-j
#         else:
#             ans+=l-i  
#     print(s,ans)
# def get_bin(x, n=0):
#     """
#     Get the binary representation of x.

#     Parameters
#     ----------
#     x : int
#     n : int
#         Minimum number of digits. If x needs less digits in binary, the rest
#         is filled with zeros.

#     Returns
#     -------
#     str
#     """
#     return format(x, 'b').zfill(n)
# for i in range(64):
#     s=get_bin(i,n=6)
#     ayob(s)
"Codeforces Round #319 (Div. 1)"
"A. Vasya and Petya's Game"
y=int(input())
a=[2]
for i in range(3,y+1,2):
    isprime=True
    for j in a:
        if i%j==0:
            isprime=False
            break
    if isprime==True:
        a.append(i)
ans=[]      
for i in a:   
    g=i        
    while g<=y:
        ans.append(g)
        g=g*i
print(len(ans))
for i in ans:
    print(i,"",end="")         