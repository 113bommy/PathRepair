#71A Way too Long Word########
#16 march 21
# for _ in range(int(input())):
#     a=input()
#     n=len(a)
#     if n<=10:
#         print(a)
#     else:
#         print(a[0]+str(n-2)+a[n-1])

#1A Theater quare 
#16 march 21
# import math
# n,m,a=map(int,input().split())
# print((math.ceil(n/a))*(math.ceil(m/a)))

#268A Games
#16 March 21

# s,a=0,[input(). split() for _ in range(int(input()))]
# for i in a:
# 	for j in a:
# 		if i[0]==j[1]: s+=1
# print(s)

#996A Hit the Lottery
#16 March 21

# n=int(input())
# a=[100,20,10,5,1]
# i=0
# c=0
# while (n!=0):
#     if n>=a[i]:
#         if n%a[i]!=0:
#             n=n-a[i]
#         # print(n)
#             c+=1
#         else :
#             c=n//a[i]
#             # print(a[i])
#             break
#     else:
#         i+=1
# print(c)
# n=int(input())
# a=[100,20,10,5,1]
# s=0
# for i in range(len(a)):
#     s+=n//a[i]
#     n=n%a[i]
# print(s)


#1472A Cards for Friends
#17 3 21
# for _ in range(int(input())):
#     a,b,n=map(int,input().split())
#     c=1
#     while(a%2==0):
#         c*=2
#         a=a//2
#     while(b%2==0):
#         c*=2
#         b=b//2
#     if n<=c:
#         print("YES")
#     else:
#         print("NO")

#1369A FashionabLee
#17 3 21
# for _ in range(int(input())):
#     n=int(input())
#     if n%4==0:
#         print("YES")
#     else:
#         print("NO")

#151A Soft Drinking
#17 3 21
a,b,c,d,e,f,g,h=map(int,input().split())
x=b*c
y=x//a
z=min(y,(d*e),(f//h))
print(int(z//g))