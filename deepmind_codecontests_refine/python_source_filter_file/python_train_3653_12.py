#https://codeforces.com/contest/1003/problem/B

a,b,x = map(int,input().split())
n1 = x%2
n2 = x//2

if n1==1 and a>=b:
    print("01"*n2 + "0"*(b-n2) + "1"*(a-n2))
elif n1==1 and a<b:
    print("10"*n2 + "1"*(b-n2) + "0"*(a-n2))
elif n1==0 and a>=b:
    print("01"*(n2) + "1"*(b-n2) + "0"*(a-n2))
elif n1==0 and a<b:
    print("10"*(n2) + "0"*(a-n2) + "1"*(b-n2))         



# while i < n:
#     if a>0:
#         if y!=0 and a>1:
#             s.append("00")
#             i+=2
#             y-=1
#             a-=2

#         else:
#             s.append("0")
#             i+=1
#             a-=1

#     if b>0:
#         if i<n:
#             if y!=0 and b>1:
#                 s.append("11")
#                 i+=2
#                 y-=1
#                 b-=2
#             else:
#                 s.append("1")
#                 i+=1
#                 b-=1
    

# s = "".join(s)
# print(s)

# if a>1 and b>1 and x>1:
#     s.append("01")
# elif a>1:
#     s.append("0")
# elif b>1:
#     s.append("1")