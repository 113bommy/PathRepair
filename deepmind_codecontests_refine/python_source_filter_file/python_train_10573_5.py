# n=int(input())
# if(n%2==0):
#     print("YES")
# else:
#     print("NO")
# for _ in range(int(input())):
#     n=(input())
#     if(len(n)<=10):
#         print(n)
#     else:
#         print(n[0]+str(len(n)-2)+n[len(n)-1])
# a=0
# for _ in range(int(input())):
#     n=list(map(int,input().split()))
#     count=0
    
#     for i in range(len(n)):
#         if(n[i]==1):
#             count+=1
#         else:
#             count-=1
#     if(count>0):
#         a+=1
# print(a)
# n,m=map(int,input().split())
# a=list(map(int,input().split()))
# count=0
# for i in range(len(a)):
#     if(a[i]>=a[m-1] and a[i]>0):
#         count+=1
# print(count)
# n,m=map(int,input().split())
# # if((n*m)%2!=0):
# print((n*m)//2)
# # else:
# #     print((n*m)//2)\
# x=0
# for _ in range(int(input())):
#     n=input()
#     if(n=="X++" or n=="++X"):
#         x=x+1
#     else:
#         x=x-1
# print(x)
# n = input()
# m = input()
# n = n.lower()
# m = m.lower()
# if n == m:
#     print("0")
# elif n > m:
#     print('1')
# elif n <m:
#     print('-1')
# matrix=[]
# min=[]
# one_line=0
# one_column=0
# for l in range(0,5):
#     m=input().split()
#     for col,ele in enumerate()

# a = list(map(int,input().split('+')))
# a.sort()
# print('+'.join([str(c) for c in a]))
# n=list(input())
# # if(n[0].islower()):
#     n[0]=n[0].upper()
# else:
#     pass
# print("".join(str(x)for x in n))
# n=list(input())
# s=input()
# count=0
# for i in range(1,len(s)):
#     if(s[i]==s[i-1]):
#         count+=1
# print(count)
# v=["A","O","Y","E","U","I","a","i","e","o","u","y"]
# n=list(input())
# x=[]
# for i in range(len(n)):
#     if n[i] not in v:
#         x.append(n[i])
# print("."+".".join(str(y.lower())for y in x))
# a=[]
# b=[]
# c=[]
# for _ in range(int(input())):
#     x,y,z=map(int,input().split())
#     a.append(x)
#     b.append(y)
#     c.append(z)
# print("YES" if sum(a)==sum(b)==sum(c)== 0 else "NO") 
# m = "hello"
# n=input()
# j=0
# flag=0
# for i in range(len(n)):
#     if(n[i]==m[j]):
#         j=j+1
#     if(j==5):
#         flag=1
#         break
# if(flag==1):
#     print("YES")
# else:
#     print("NO")
# a=set(list(input()))
# print("CHAT WITH HER!" if len(set(list(input())))%2==0 else "IGNORE HIM!")
# k,n,w=map(int,input().split())
# sum=0
# a=[]
# for i in range(w+1):
#     sum+=k*i
# print((sum-n) if sum>n else 0)
# m,n = 0,0
# for i in range(5):
# 	a = map(int,input().split())
# 	for j in range(5):
# 		if a[j]!=0:
# 			m = i
# 			n = j
# 			break
# print(abs(m-2)+abs(n-2))
# l,b=map(int,input().split())
# c=0
# while(l<=b):
# 	l=l*3
# 	b=b*2
# 	c=c+1
# print(c)
# from math import ceil 
# n,m,a=map(int,input().split()) 
# # print(ceil(n/a),ceil(m/a))
# c=ceil(n/a)*ceil(m/a)  
# print(c) 
# n=int(input())
# if(n%4==0 or n%7==0 or n%44==0 or n%47==0 or n%74==0 or n%444==0 or n%447==0 or n%474==0 or n%477==0):
# 	print("YES")
# else:
# 	print("NO")
# def tramCapacity():
#     n = int(input().strip())
#     pout, pin = map(int, input().strip().split())
#     sm = pin
#     mx = pin
#     for i in range(n-1):
#         pout, pin = map(int, input().strip().split())
#         sm = sm - pout + pin
#         if sm > mx:
#             mx = sm
#     return mx

# print(tramCapacity())
# n,k=map(int,input().split())
# for i in range(k):
# 	if(str(n)[-1]=="0"):
# 		n=n//10
# 	else:
# 		n=n-1
# print(n)
# n=int(input())
# n=int(input())
# if(n%5==0):
# 	print(n//5)
# else:
# 	print((n//5)+1)
# n=int(input())
# if(n%2==0):
#     print(n//2)
# else:
#     print("-"+str(n-((n-1)//2)))
# n=int(input())
# arr=list(map(int,input().split()))
# sum=sum(arr)
# deno=len(arr)*100
# print(format(((sum/deno)*100),'.12f'))
# k=int(input())
# l=int(input())
# m=int(input())
# n=int(input())
# d=int(input())
# count=0
# # if(d%k==0):
# #     print(d)
# # elif(d%l==0):
# #     print(d//l)
# # elif(d%m==0):
# #     print(d//m)
# # elif(d%n==0):
# #     print(d//n)
# # else:
# for i in range(1,d+1):
#     if(i%k==0 or i%l==0 or i%m==0 or i%n==0):
#         count+=1
# print(count)

# a,b=map(int,input().split())
# # if(n%m==0):
# #     print(0)    
# # else:
# #     for i in range(m):
# #         n=n+i
# #         if(n%m==0):
# #             print(i-1)
# #             break
# #         else:
# #             continue
# x=((a+b)-1)/b
# print((b*x)-1)
# for _ in range(int(input())):
#     a, b = map(int,input().split(" "))
#     x=(a + b - 1) // b
#     # print(x)
#     print((b * x) - a)
# for _ in range(int(input())):
#     n=int(input())
#     print((n-1)//2)
# n=int(input())
# # n = int(input())
# if n%2 == 0:
#     print(8, n-8)
# else:
#     print(9, n-9)
# n=int(input())
# a=[]
# for i in range(len(n)):
#     x=int(n)-int(n)%(10**i)
#     a.append(x)
# print(a)
# # b=max(a)
# print(a[-1])
# for i in range(len(a)):
#     a[i]=a[i]-a[-1]
# print(a)
# for _ in range(int(input())):
#     n=int(input())
#     p=1
#     rl=[]
#     x=[]
#     while(n>0):
#         dig=n%10
#         r=dig*p
#         rl.append(r)
#         p*=10
#         n=n//10
#     for i in rl:
#         if i !=0:
#             x.append(i)
#     print(len(x))
#     print(" ".join(str(x)for x in x))
# n,m=map(int,input().split())
# print(str(min(n,m))+" "+str((max(n,m)-min(n,m))//2))
# arr=sorted(list(map(int,input().split())))
# s=max(arr)
# ac=arr[0]
# ab=arr[1]
# bc=arr[2]
# a=s-bc
# b=ab-a
# c=bc-b
# print(a,b,c)
# x=0
# q,t=map(int,input().split())
# for i in range(1,q+1):
#     x=x+5*i
#     if(x>240-t):
#         print(i-1)
#         break
# if(x<=240-t):
#     print(q)       
# # print(q)
# print(z)
# print(x)
# l=(240-t)-x
# print(l)
# if(((240-t)-x)>=0):
#     print(q)
# else:
#     print(q-1)
# n, L = map(int, input().split())
# arr = [int(x) for x in input().split()]
# arr.sort()

# x = arr[0] - 0
# y = L - arr[-1]

# r = max(x, y) * 2

# for i in range(1, n):
#     r = max(r, arr[i] - arr[i-1])

# print(format(r/2,'.12f'))

# n,m=map(int,input().split())
# print(((m-n)*2)-1)
# for _ in range(int(input())):
#     n=int(input())
#     x=360/(180-n)
#     # print(x)
#     if(n==60 or n==90 or n==120 or n==108 or n==128.57 or n==135 or n==140 or n==144 or n==162 or n==180):
#         print("YES")
#     elif(x==round(x)):
#         print("YES")
#     else:
#         print("NO")
# n,m=map(int,input().split())
# if(n<2 and m==10):
#     print(-1)
# else:
#     x=10**(n-1)
#     print(x+(m-(x%m)))
# for _ in range(int(input())):
#     n,k=map(int,input().split())
#     a=list(map(int,input().split()))
#     a.sort()
#     c=0
#     for i in range(1,n):
#         c = (k-a[i])//a[0]
# #         print(c)
# for _ in range(int(input())):
#     x,y=map(int,input().split())
#     a,b=map(int,input().split())
#     q=a*(x+y)
#     p=b*(min(x,y))+a*(abs(x-y))
#     print(min(p,q))
# n,k=map(int,input().split())
# a=n//2+n%2
# print(a)
# if(k<=a):
#     print(2*k-1)
# else:
#     print(2*(k-a))
# a,b=map(int,input().split())
# count=0
# if(a>=b):
#     print(a-b)
# else:
#     while(b>a):
#         if(b%2==0):
#             b=int(b/2)
#             count+=1
#         else:
#             b+=1
#             count+=1
#     print(count+(a-b))
# n=int(input())
# while n>5:
#     n = n - 4
#     n=(n-((n-4)%2))/2
# # print(n)
# if n==1:
# 	print('Sheldon')
# if n==2:
# 	print('Leonard')
# if n==3:
# 	print('Penny') 
# if n==4:
# 	print('Rajesh')
# if n==5:
#     print('Howard')
# n, m = (int(x) for x in input().split())
# if(n<m):
#     print(-1)
# else:
#     print((int((n-0.5)/(2*m))+1)*m)
# for _ in range(int(input())):
#     n,k=map(int,input().split())
#     print(k//n)
#     print(k%n)
#     if((k+(k//n))%n==0):
#         print(k+(k//n)+1)
#     else:
#         print(k+(k//n))
# for i in range(int(input())):
#     n,k=map(int,input().split())
#     print((k-1)//(n-1) +k)
# for _ in range(int(input())):
#     n,k = map(int,input().split())
#     if (n >= k*k and n % 2 == k % 2):
#         print("YES")
#     else:
#         print("NO")
# for _ in range(int(input())):
#     n,x=map(int,input().split())
#     a=list(map(int,input().split()))
#     arr=[]
#     # s=sum([i%2 for i in a])
#     for i in a:
#             j=i%2
#             arr.append(j)
#     s=sum(arr)
#     # print(s)
#     if s==0 or (n==x and s%2==0) or (s==n and x%2==0):
#         print("No")
#     else:
#         print("Yes")
# a=int(input())
# print(a*(a*a+5)//6)

# n,m=map(int,input().split())
# a=[]
# k='YES'
# for i in range(m): 
#     a.append(list(map(int,input().split())))
# a.sort()
# for i in a:
#     if i[0]<n:
#         n=n+i[1]
#     else:
#         k='NO'
#         break
# print(k)

# a=input()
# if('1'*7 in a or '0'*7 in a):
#     print("YES")
# else:
#     print("NO")


# s=int(input())
# for i in range(s):
#     n=int(input())
#     if (n//2)%2==1:
#         print('NO')
#     else:
#         print('YES')
#         for j in range(n//2):
#             print(2*(j+1))
#         for j in range(n//2-1):
#             print(2*(j+1)-1)
#         print(n-1+n//2)
# k,r=map(int,input().split())
# i=1

# while((k*i)%10)!=0 and ((k*i)%10)!=r:
#     i=i+1
# print(i)
# for _ in range(int(input())):
#     n,m=map(int,input().split())
#     if(abs(n-m)==0):
#         print(0)
#     else:
#         if(abs(n-m)%10==0):
#             print((abs(n-m)//10))
#         else:
#             print((abs(n-m)//10)+1)
# a,b,c=map(int,input().split())
# print(max(a,b,c)-min(a,b,c))
# a=int(input())
# arr=list(map(int,input().split()))
# print(a*max(arr)-sum(arr))

# for _ in range(int(input())):
#     a, b = map(int, input().split())
#     if a==b:
#         print((a+b)**2)
#     elif max(a,b)%min(a,b)==0:
#         print(max(a,b)**2)
#     else:
#         ans=max(max(a,b),2*min(a,b))
#         print(ans**2)
# import math
# # for _ in range(int(input())):
# x=int(input())
# a=list(map(int,input().split()))
# for j in range(len(a)):
#     n=math.sqrt(a[j])
#     flag=0
#     if(a[j]==1):
#         print("NO")
#     elif(n==math.floor(n)):
#         for i in range(int(n)):
#             if((6*i)-1==n or ((6*i)+1==n) or n==2 or n==3 or n!=1):
#                     # print("YES")
#                 flag=1
#                 break
#             else:
#                 flag=0
#         print("YES" if flag==1 else "NO")
#     else:
#         print("NO")
# print(12339-12345)
# for _ in range(int(input())):
#     x,y,n=map(int,input().split())
#     # for i in range((n-x),n):
#     #     # if(i%x==y):
#     #     print(i)
#     print(n-(n-y)%x)
# n=int(input())
# for _ in range(int(input())):
# 	n= int(input())
# 	print(int(2**(n//2+1)-2))
# for _ in range(int(input())):
#   n=int(input())  
#   arr=list(map(int,input().split()))
#   countod=0
#   countev=0
#   for i in range(n):
#     if i%2==0 and arr[i]%2!=0:
#       countev+=1
#     elif i%2!=0 and arr[i]%2==0:
#       countod+=1
#   if countod!=countev:
#     print(-1)
#   else:
#     print(countev)
# n,m=map(int,input().split())
# x=m/(n//2)
# print(x)
# print(int(x*(n-1)))
# for _ in range(int(input())):
#     n,m = map(int,input().split())
#     print(m*min(2,n-1))
# n=int(input())
# if(n%2==0):
#     print(n//2)
#     print('2 '*(n//2))
# else:
#     print(((n-2)//2)+1)
#     print('2 '*(((n-2)//2)) + "3") 
# for _ in range(int(input())):
#     n=int(input())
#     for i in range(2,30):
#         if(n%(2**i - 1)==0):
#             print(n//(2**i - 1))
#             break
# a,b=map(int,input().split())
# print((a-1)//(b-1)+a)
# for _ in range(int(input())):
#     n=int(input())
#     print(n//2)
# for _ in range(int(input())):
#     n=int(input())
#     if(n%2==0):
#         print(n//2)
#     else:
#         print((n//2)+1)
# for _ in range(int(input())):
#     a,b = map(int, input().split())
#     count = 0
#     while(min(a,b) != 0):
#         x=max(a,b)
#         y = min(a,b)
#         a = y
#         b=x
#         count += b//a
#         b = b % a
#     print(count)
# n,k=map(int,input().split())
# a=list(map(int,input().split()))
# m=min(a)
# c=0
# for i in a:
#     if (i-m)%k!=0:
#         print(-1)
#         break
#     c+=(i-m)//k
# else:
#     print(c)

# a,b = map(int,input().split())
# l = b-(2*a)
# if l < a:
# 	print(a-l)
# else:
# 	print(0)
# for _ in range(int(input())):
#     n = int(input())
#     n2 = 0
#     n3 = 0
#     while n % 2 == 0:
#         n2 += 1
#         n //= 2
#     while n % 3 == 0:
#         n3 += 1
#         n //= 3
#     if n != 1 or n2 > n3:
#         print(-1)
#     else:
#         print(2 * n3 - n2)
# t=int(input())
# for _ in range(t):
#   x,n,m=map(int,input().split())
#   while x>20 and n>0:
#     x=x//2+10
#     n-=1
#   while m>0:
#     x=x-10
#     m-=1
#   if x<=0:
#     print("YES")
#   else:
#     print("NO")
# for _ in range(int(input())):
# 	print(int(input()))
# t=int(input())
# for i in range(t):
# 	n,a,b,c,d=map(int,input().split())
# 	if (a-b)*n<=c+d and c-d<=(a+b)*n:
# 		print('YES')
# 	else:
# 		print('NO')

# for t in range(int(input())):
#     x, y = map(int, input().split())
#     print((x*y+1)//2)

# t = int(input())
# for _ in range(t):
#   a,b=list(map(int,input().split()))
#   if b==a:
#     print(0)
#   if b>a:
#     print((2-(b-a)%2))
#   if b<a:
#     print((1+(a-b)%2))


# t = int(input())
# for _ in range(t):
#     a, b, c, n = map(int, input().split())
#     # if (a+b+c+n) % 3 == 0 and (((a+b+c+n) // 3) >= max(a, b, c)):
#     #     print("YES")
#     # else:
#     #     print("NO")
#     m = max(a,b,c)
#     d = n-(sum([abs(m-a),abs(b-m),abs(c-m)]))
#     print("YES" if(d>=0 and d%3==0) else "NO")


# for _ in range ( int(input()) ):
#     x,y,z = sorted (map(int,input().split()))
#     # print(x,y,z)
#     if y == z  :
#         print("YES")
#         print (x,1,z)
#     else:
#         print("NO") 


# n=int(input())
# a=list(map(int,input().split()))
# x=sum(a)
# y=0
# count=0
# while(y<=x):
#     y+=max(a)
#     x=x-max(a)
#     a.remove(max(a))
#     count+=1
# print(count)

# s = input()
# flag=0
# for x in 'HQ9':
#     if x in s:
#         flag=1
# print("YES" if flag==1 else "NO")
# import math
# n=int(input())
# a=list(map(int,input().split()))
# s=sum(a)
# print(math.floor(s//4)+1)

# from math import ceil
# n=int(input())
# s=list(map(int,input().split()))
# a=s.count(4)
# b=s.count(3)
# c=s.count(2)
# d=s.count(1)
# p=a+b
# if d<=b:
#     p=p+ceil(c/2)
# else :
#     p=p+ceil((d-b+2*c)/4)
# print(p)

# s=input()
# uc=lc=0
# for i in s:
#     if i.isupper():
#         uc+=1
#     else:
#         lc+=1
# # print(uc,lc)
# if(lc>=uc):
#     s=s.lower()
# else:
#     s=s.upper()
# print(s)

# s=input()
# m=input(),
# print("YES" if s[::-1]==m else "NO")
# a=input()
# n=input()
# dc=ac=0
# for i in n:
#     if i=='D':
#         dc+=1
#     else:
#         ac+=1
# if dc>ac:
#     print("Danik")
# elif(ac>dc):
#     print("Anton")
# else:
#     print("Friendship")

# n=input()
# if len(n)==1:
#     print(n.swapcase())
# else:
#     if n.isupper():
#         print(n.lower())
#     else:
#         if n[1:].isupper():
#             print(n.capitalize())
#         else:
#             print(n)

# print(*input().split('WUB'))

# s={"Tetrahedron":4,"Cube":6,"Octahedron":8,"Dodecahedron":12,"Icosahedron":20}
# c=0
# for i in range(int(input())):
#     c+=s[input()]
# print(c)

# a=input()
# print("YES" if len(set(input().lower())) == 26 else "NO")

# for _ in range(int(input())):
#     n=int(input())
#     s=input()
#     while '()' in s:
#         s=s.replace('()','')
#     # print(s)
#     print(len(s)//2)

# m = "hello"
# n=input()
# j=0
# flag=0
# for i in range(len(n)):
#     if(n[i]==m[j]):
#         j=j+1
#     if(j==5):
#         flag=1
#         break
# if(flag==1):
#     print("YES")
# else:
#     print("NO")
# s=input()
# ab=s.count('AB')
# ba=s.count('BA')
# aba=s.count('ABA')
# bab=s.count('BAB')
# # print(ab,ba,aba,bab)
# if ab+ba-aba-bab>=2 and ab>0 and ba>0:
#     print('YES')
# else:
#     print('NO')    

# n,m=map(int,input().split())
# d={}
# for i in range(m):
# 	a,b=input().split()
# 	d[a]=b
# for x in input().split():
#     # print(d[x])
#     if len(x)<=len(d[x]) :
# 	    print(x,end=" ")
#     else:
#         print(d[x],end=" ")

# n=int(input())
# List=[]
# for i in range(n):
#     List.append(input())
# List.sort()
# print(List[n//2])

# for _ in range(int(input())):
#     s = input()
#     if s.count('0') == len(s) or s.count('0') == 0:
#         print(s)
#     else :
#         print("10" * len(s))


# for i in range(int(input())):
#     S=input()
#     print("".join(set(S))*len(S))

# t = int(input())
# for _ in range(t):
# 	n = int(input())
#     a=list(map(int,input().split()))

# for _ in range(int(input())):
#     n=int(input())
#     l=list(map(int,input().split()))
#     flag=0
    
#     for i in range(n):
#         if i+2<n:
#             if l[i] in l[i+2:]:
#                 flag=1
#                 break
#     if flag==1:
#         print('YES')
#     else:
#         print('NO')


# n=int(input())
# print("codeforces"+"s"*(n-1))

# g=(input())
# h=(input())
# c=(input())
# print("YES" if sorted(g+h)==sorted(c) else "NO")

# a,b=map(int,input().split())
# a,b=map(int,input().split())
# i=int(input())
# print((a^i)+(b^i))

# for _ in range(int(input())):
#     a,b=map(int,input().split())
#     print(a^b)
# for _ in range(int(input())):
#     n=input()
#     count=0
#     for i in n:
#         if(i=="B" and count!=0):
#             count=count-1
#         else:
#             count=count+1
#     print(count)
# n=list(input())
# count=0
# for i in range(len(n)):
#     # print(n[i])
#     if(n[i]=='4' or n[i]=='7'):
#         count+=1
# m=count
# # print(m)
# if(m==4 or m==7):
#     print("YES")
# else:
#     print("NO")


# count=0
# for _ in range(int(input())):
#     n,m=map(int,input().split())
#     if(abs(n-m)>=2):
#         count+=1
# print(count)

# n,m=map(int,input().split())
# a=map(int,input().split())
# q=0
# p=1
# for i in a:
#     q+=(i-p)%n;p=i
# print(q)

# input()
# d=[0]*100001
# for x in map(int,input().split()):
#     d[x]+=x
# a=b=0
# for i in d:
#     a,b=max(a,i+b),a
# print(a)
# def hanoisum(n):
#     s=0
#     for i in range(1,n+1):
#         s+= 2**(i-1)
#     return s
# n=int(input())
# print(hanoisum(n))

# def hanoisum(n):
#     if n==1:
#         return 1
#     return n + hanoisum(2**(n-1))
# x=int(input())
# print(hanoisum(x))

# def hanoi(x,a,b,c):
#     if(x==1):
#         print("move 1 from " + a +"to"+c)
#         return
#     hanoi(x-1,a,c,b)
#     print("move" + x + " from "+ a + "to" +c)
#     hanoi(n-1,b,a,c)
# n=int(input())
# print(hanoi(n,A,B,C))

# for i in range(int(input())):
# 	n,k=map(int,input().split())
# 	a=list(map(int,input().split()))
# 	b=list(map(int,input().split()))
# 	a.sort()
# 	b.sort(reverse=True)
# 	for j in range(k):
# 		if b[j]>a[j]:
# 			a[j],b[j]=b[j],a[j]
# 	print(sum(a))


# n, s = map(int, input().split())
# if(n==1 and s==0):
#     print('0 0')
# elif(9*n < s or s == 0):
#     print('-1 -1')
# else:
#     x1 = 10**(n-1)
#     for i in range(s-1):
#         x1 += 10**(i//9)
#     x2 = 0
#     for i in range(s):
#         x2 += 10**(n-1-i//9)
#     print(x1, x2)


# n=int(input())
# s=n+1
# while len(set(str(s)))<4:
#     s+=1
# print(s)


# t=int(input())
# for i in range(t):
# 	n=int(input())
# 	c=list(map(int,input().split()))
# 	o=list(map(int,input().split()))
# 	minc=min(c)
# 	mino=min(o)
# 	ans=0
# 	for j in range(n):
# 		ans+=max(abs(minc-c[j]),abs(mino-o[j]))
# 	print(ans)


# for t in range(int(input())):
#     n = int(input())
#     l = sorted(list(map(int,input().split())))
#     a=[]
#     for i in range(n-1):
#         x=l[i+1]-l[i]
#         a.append(x)
#     print(min(a))

# b=int(input())
# boys=list(map(int,input().split()))
# boys.sort()
# g=int(input())
# girls=list(map(int,input().split()))
# girls.sort()
# count=0
# for boy in boys:
# 	for i in range(g):
# 		if abs(boy-girls[i])<=1:
# 			count+=1
# 			girls[i]=-2
# 			break
# print(count)



# for _ in range(int(input())):
#     a=int(input())
#     l=list(map(int,input().split()))
#     s=[]
#     for i in l:
#         if i not in s:
#             s.append(i)
#     print(" ".join(str(x)for x in s))


# n,x=map(int,input().split())
# s=input()
# for i in range(x):
#     s=s.replace("BG","GB")
# print(s)

# n, m = map(int,input().split())
# a = sorted(map(int,input().split()))
# x=[]
# for i in range(m-n+1):
#     x.append((a[i+n-1]-a[i]))
# print(min(x))


# for i in range(int(input())):
#     x=int(input())
#     print(2)
#     print(x,x-1)
#     for i in range(x-2):
#         print(x,x-2)
#         x=x-1


# mc=0
# cc=0
# t=int(input())
# for i in range(t):
#     m,c=map(int,input().split())
#     if(m>c):
#         mc+=1
#     elif(m<c):
#         cc+=1
# if(mc>cc):
#     print("Mishka")
# elif(cc>mc):
#     print("Chris")
# else:
#     print("Friendship is magic!^^")



# n,a,b,c = map(int,input().split())
# a,b,c = sorted([a,b,c])[::-1]
# ans = 0
# for i in range(n//a+1):
# 	for j in range(n//b+1):
# 		k = (n-i*a-j*b)//c
# 		if i*a+b*j+k*c==n and k>=0:
# 			ans = max(ans,i+j+k)
# 			break
# print(ans)


# n=int(input())
# b=input().split()
# for i in range(n):
# 	print(b.index(str(i+1))+1,end=" ")

# import math
# x=int(input())
# next = math.floor(math.log(x)/math.log(2))
# print(next)
# y= pow(2,math.ceil(math.log(x)/math.log(2)))
# print(next-(x-y))


# n=int(input())
# count=0
# while(n!=0):
#     if(n%2==1):
#         count+=1
#     n=n//2
# print(count)

# t=int(input())
# for _ in range(t):
#     a,b=map(int,input().split())
#     if(a!=0)and(b!=0):
#         res=(a+b)//3
#     else:
#         res=0
#     print(min(res,a,b))

# n=int(input())
# ar=list(map(int,input().split()))
# for i in range(0,n):
#     a=ar[i]%2
#     b=ar[(i+1)%n]%2
#     c=ar[(i-1)%n]%2
#     if(a!=b) and a!=c:
#         print(i+1)
#         break

# n=int(input())
# arr=list(map(int,input().split()))
# arr.sort()
# print(*arr)

# n,h=map(int,input().split())
# a=list(map(int,input().split()))
# count=0
# for i in a:
#     if i>h:
#         count+=2
#     else:
#         count+=1
# print(count)

# int(input())
# count=1
# cc=1
# a=list(map(int,input().split()))
# for i in range(len(a)-1):
#     if(a[i+1]>=a[i]):
#         count+=1
#     else:
#         count=1
#     cc=max(cc,count)
# print(cc)

# t=int(input())
# s=""
# while t:
#     s+=input()
#     t-=1
# one=s.count("11")
# zero=s.count("00")
# print((one+zero)+1)
# n=input()
# m=input()
# x=[]
# for i in range(len(n)) :
#     if n[i]!=m[i]:
#         x.append(1)
#     else:
#         x.append(0)
# print("".join(str(x)for x in x))

# int(input())
# print("HARD" if 1 in list(map(int,input().split())) else "EASY")

# n = int(input())
# print('I hate' + ' that I love that I hate' * ((n-1)// 2)*(n > 2) + ' that I love' * ((n + 1) % 2) +' it')


# a=int(input())
# b=list(map(int,input().split()))
# c=list(map(int,input().split()))
# d=b[1:]+c[1:]
# if(len(set(d))==a):
#     print("I become the guy.")
# else:
#     print("Oh, my keyboard!")


# a=len(set(input().split()))
# print(4-a)
#     if (u,v) in mem:
#         print(mem[(u,v)])
        
#     else:
#         x=len(dict[u].f)
#         uval=dict[u].f
#         vval=dict[v].f
#         ans=0
        
#         for i in range(len(uval)):
#             ans+=uval[i]*vval[i]
            
#         ans=ans%(2**32)
#         mem[(u,v)]=ans
# print(ans)


# for _ in range(int(input())):
#     n,c0,c1,h=map(int,input().split())
#     s=input()
#     x=s.count('0')
#     y=s.count('1')
#     o=((x*c0)+(y*c1))
#     a=h*x
#     b=h*y
#     cz=(n*c0)+b
#     con=(n*c1)+a
#     print(min(cz,con,o))

# n=int(input())
# k=int(input())
# z=k
# a=list(map(int,input().split()))
# b=len(a)
# i=-n
# s=0
# # print(a[-2],a[-4],a[-6],a[-8])
# while(i>=-b):
#     print(a[i])
#     i-=n

# n,d=int(input()),{}
# for i in range(n):
# 	s=input()
# 	if s not in d:
# 		d[s]='0'
# 		print('OK')
# 	else:
# 		d[s]=str(int(d[s])+1)
# 		print(s+d[s])



# from math import factorial

# n=int(input())
# a=input()
# f=1
# for i in a:
#     f*=factorial(int(i))

# # print(f)

# for d in (7,5,3,2):
#     while(f>1):
#         if(f%d==0):
#             print(d,end='')
#             # print(factorial(d))
#             f=f//factorial(d)
#             # print(f)
#         else:
#             break


# import math
# for _ in range(int(input())):
#     n,m,k=map(int,input().split())
#     c=n//k
#     a=min(m,c)
#     b=math.ceil((m-a)/(k-1))
#     print(a-b)

# for _ in range(int(input())):
#     n=int(input())
#     print(len(n))

# n=int(input())
# if n%2==0:
#     print(n//2)
# else:
#     c=n-(n//2)
#     print(-c)

# for _ in range(int(input())):
#     s=input()
#     print(s[::2]+s[-1])

# for _ in range(int(input())):
#     n,k=map(int,input().split())
#     x=[]
#     if (n==k):
#         for i in range(1,n+1):
#             x.append(i)
#         print(*x)
#     else:
#         if (k<n//2):
#             for i in range(1,n+1):
#                 x.append(-i)
#             for i in range(0,2*k,2):
#                 x[i]*=-1
#             print(*x)
#         else:
#             for i in range(1,n+1):
#                 x.append(i)
#             for i in range(0,2*(n-k),2):
#                 x[i]*=-1
#             print(*x)

# import sys
# sys.stdin = open("input.txt","r")
# sys.stdout = open("output.txt","w")
# n,k=map(int,input().split())
# arr=list(map(int,input().split()))
# x=0
# for i in range(n):
#     if arr[i]<k:
#         x+=arr[i]
#     else:
#         x+=arr[i]-k*min(3,arr[i]//k)
# print(x)


#25 May
# s=list(set(input()))
# arr=[]
# for i in s:
#     if i.isalpha():
#         arr.append(i)
# print(len(set(arr)))
# a,b=map(int,input().split())
# x=0
# for i in range(a):
#     if i%2==0:
#         print("#"*b)
#     else:
#         if x%2==0:
#             print('.'*(b-1)+"#")
#             x+=1
#         else:
#             print("#"+"."*(b-1))
#             x+=1
#26 May
# for _ in range(int(input())):
#     n=int(input())
#     arr=list(map(int,input().split()))
#     a=list(set(arr))
#     a.sort()
#     if (max(a)-min(a))<len(a):
#         print("YES")
#     else:
#         print("NO")
    # else:
    #     for i in range(1,len(a)):
    #         a[i]=a[i]-a[i-1]
    #     if len(set(a))>1:
    #         print("NO")
    #     else:
    #         ar=list(set(a))
    #         if ar[0]==1:
    #             print("YES")
    #         else:
    #             print("NO")

# n=int(input())
# arr=list(map(int,input().split()))
# minn=maxx=arr[0]
# count=0
# for i in range(1,n):
#     if arr[i]>maxx:
#         count+=1
#         maxx=arr[i]
#     elif arr[i]<minn:
#         count+=1
#         minn=arr[i]
# print(count)

# n,m,a,b=map(int,input().split())
# if (b/m)<=a:
#     if (n%m)==0:
#         s=n//m
#         summ = s*b
#         print(summ)
#     else:
#         # res=n%m
#         # s=n//m
#         summ = ((n//m)*b) + ((n%m)*a)
#         # res=1
#         # s=(n//m)+1
#         summm = (((n//m)+1)*b)
#         print(min(summ,summm))
# else:
#     print(n*a)

# 27 May 
# n=int(input())
# arr=list(map(int,input().split()))
# s=0
# c=0
# for i in arr:
#     s+=i
#     if s<0:
#         c+=1
#         s=0
# print(c)

# n,k = map(int,input().split())
# arr=list(map(int,input().split()))
# c=0
# for i in arr:
#     if (5-i)>=k:
#         c+=1
# print(c//3)
# a,b=map(int,input().split())
# print((a-1)//(b-1)+a)

#28 May
# for _ in range(int(input())):
#     n=int(input())
#     a=list(map(int,input().split()))
#     if((a.count(1)%2==0 and a.count(1)>0) or len(a)==0 or (a.count(2)%2==0 and a.count(1)%2==0)):
#         print('YES')
#     else:
#         print('NO')

#2 2 4
# 5 7 2
# for _ in range(int(input())):
# 	n=int(input())
# 	s=list(map(int,input().split()))
# 	e=0
# 	o=0
# 	for i in s:
# 		if(i%2==0):
# 			e+=1
# 		else:
# 			o+=1
# 	if((o==n and n%2==0) or e==n):
# 		print("NO")
# 	else:
# 		print("YES")

#29 May
# s=list(map(int,input().split()))
# n=input()
# x=0
# for i in n:
#     x+=s[int(i)-1]
# print(x)

# import math
# n=int(input())
# print(int(math.factorial(2*(n-1))/(math.factorial(n-1)**2)))

# def maximumOccuringCharacter(s):
#     arr=[0]*255
#     for i in s:
#         arr[ord(i)]+=1
#     m=max(arr)
#     for i in range(255):
#         if arr[i]==m:
#             return chr(i)
# s=input()
# print(maximumOccuringCharacter(s))

# for _ in range(int(input())):
#     hr,mn = map(int,input().split())
#     ts = 60*24
#     s = (hr*60)+mn
#     print(ts-s)

# if (int(input())) % 2==0:
#     print("Mahmoud")
# else:
#     print("Ehab")

#30 May

# for _ in range(int(input())):
#   a,b,c,d=map(int,input().split())
#   print(b,c,c)

# import math
# for _ in range(int(input())):
#     n,x = map(int,input().split())
#     if n==1:
#         print(1)
#     else:
#         n=n-2
#         print(math.ceil(n/x)+1)

#31 May
# for i in range(int(input())):
#     a,b,n=map(int,input().split())
#     if a<b:
#         a,b=b,a
#     cnt=0
#     while a<=n:
#         a,b=a+b,a
#         cnt+=1
#     print(cnt)

#2 Apr
a,b,c,d=map(int,input().split())
x=min(a,c,d)
ans=(x*256)
a-=x
x=max(a,b)
ans+=(x*32)
print(ans)