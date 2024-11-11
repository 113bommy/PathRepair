ip = lambda : list(map(int, input().split()))

########################################

#      K-th Beautiful String           #

########################################

# for _ in range(int(input())):
#     m, n = map(int, input().split())
#     j = 1
#     i = 1
#     if(n == 2 or n == 3):
#         a = 1
#     else:
#         a = 0
#     while(j < n):
#         i += 1
#         j += i
#         if(j < n):
#             a = j
#     s = 'a'*(m)
#     # print(a)
#     i = m - i - 1
#     s = s[:i]+'b'+s[i+1:]
#     i = m - (n - a - 1) - 1
#     s = s[:i]+'b'+s[i+1:]
#     print(s)

########################################

#   B. A and B and Compilation Errors  #

########################################

# n = int(input())
# a = sum(list(map(int, input().split())))
# b = sum(list(map(int, input().split())))
# print(a-b)
# c = sum(list(map(int, input().split())))
# print(b-c)

########################################

#        B. Phoenix and Beauty         #

########################################

# for _ in range(int(input())):
#     n, k = map(int, input().split())
#     ar = list(map(int, input().split()))
#     op = []
#     ch = set(ar)
#     if(len(ch) > k):
#         print(-1)
#         continue
#     mi = 1
#     while(len(ch) != k):
#         if(mi not in ch):
#             ch.add(mi)
#         mi += 1
#     op = list(ch)
#     out = " ".join(str(x) for x in op)+" "
#     print(len(op)*n)
#     print(out*n)

########################################

#          B. The Great Hero           #

########################################

# from math import ceil
# for _ in range(int(input())):
#     a,b,n = map(int, input().split())
#     po = list(map(int, input().split()))
#     ip = list(map(int, input().split()))

#     f=0
#     c = []
#     for i in range(n):
#         c.append((po[i],ip[i]))
#     c.sort()
#     for i in range(n):
#         # if(b <= 0):
#         #     f = 1
#         #     break
#         v = ceil(ip[i]/a)
#         # v2 = ceil(b/po[i])
#         # print(v)
#         b -= (v*po[i])
#         # ip[i] -= (v*a)
#         # if(v2<v):
#         #     f=1
#         #     break
#     if(b > -c[-1][0]):
#         print("YES")
#     else:
#         print("NO")

########################################

#         B. The Cake Is a Lie         #

########################################

# for _ in range(int(input())):
#     x,y,k = map(int, input().split())
#     s1 = 1*y
#     s1 -= 1
#     s1 += y*x
#     s1 -= y
#     s2 = 1*x
#     s2 -= 1
#     s2 += x*y
#     s2 -= x
#     if(s1 == k or s2 == k):
#         print("yEs")
#         continue
#     print("No")

########################################

#         B. Interesting drink         #

########################################

# n = int(input())
# pri = list(map(int, input().split()))
# s = set()
# d = {}
# for i in pri:
#     if(i in s):
#         d[i] = d[i] + 1
#     else:
#         s.add(i)
#         d[i] = 1
# day = int(input())
# mi = min(pri)
# ma = max(pri)
# dp = [0]*(ma+1)
# for i in range(mi,ma+1):
#     if(i in s):
#         dp[i] = dp[i-1]+d[i]
#     else:
#         dp[i] = dp[i-1]
# print(dp)
# for _ in range(day):
#     co = int(input())
#     if(co>ma):
#         print(n)
#     else:
#         print(dp[co])

########################################

#            B. BerSU Ball             #

########################################

# lip = lambda : map(int, input().split())

# b = int(input())
# boys = list(lip())

# g = int(input())
# girls = list(lip())

# boys = sorted(boys, reverse=True)
# girls = sorted(girls, reverse=True)

# i = 0
# j = 0
# op = 0
# while(i<b and j<g):
#     if(abs(girls[j]-boys[i])<=1):
#         op += 1
#         i += 1
#         j += 1
#     elif((girls[j]-boys[i])>1):
#         j += 1
#     elif((boys[i]- girls[j])>1):
#         i += 1
# print( op )

########################################

#       B. Phoenix and Puzzle          #

########################################

# from math import log2,ceil,floor,sqrt

# for _ in range(ip()[0]):
#     n = ip()[0]
#     a = log2(n)
#     c = sqrt(n/2)
#     d = sqrt(n/4)
#     if(floor(a) == ceil(a) and n!= 1):
#         print("YES")
#     elif((floor(c) == ceil(c) or floor(d) == ceil(d)) and n!= 1):
#         print("YES")
#     else:
#         print("NO")

########################################

#             B. Fence                 #

########################################

inp = ip()
n,k = inp[0],inp[1]
h = ip()

dp=[]
s = 0
for i in range(0,k):
    s+= h[i]

dp.append(s)
for i in range(1,n-k+1):
    s -= h[i-1]
    s += h[i-1+k]
    dp.append(s)
# print(dp)
print(dp.index(min(dp))+1)