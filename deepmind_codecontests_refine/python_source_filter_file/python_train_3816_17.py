import math

#################### Problems from CodeForces solved by Sohaib Moradi aka Shmits ####################

######################################################################### 1
###### World Cup ###### A problem from CodeForces ###### Wordl Cup ######
## tags: binary search, math

# def func(As, n, entranceNum=0):
#
#     Min = min(As)
#     p = entranceNum
#
#     while True:
#         if As[p] == 0:
#             return p+1
#
#         if p != n-1:
#             for i in range(p + 1, n):  # checking the right side of position p in As for possible answer after 'Min'
#                 # steps
#                 d = i - p   # distance between position i in As and position p in As  (Right side)
#                 if As[i] <= d:
#                     return i + 1
#
#         for i in range(p):  # checking the left side of position p in As for possible answer after 'Min' steps
#             d = n - p + i   # distance between position i in As and position p in As  (Left side)
#             if As[i] <= d:
#                 return i + 1
#
#         As = [As[i] - Min for i in range(n)]
#         p = (Min % n + p) % n
#         Min = min(As)
#
#
# num = int(input())
# A = list(map(int, input().split(" ")))
#
# print(func(A, num))
#########################################################################

######################################################################### 2
###### Hit the Lottery ###### A problem from CodeForces ###### Hit the Lottery ######
## tags: dp, greedy

############ greedy approach ############
# coins = [1, 5, 10, 20, 100]
#
# cash = int(input())
# coinsNum = 0
# for i in range(len(coins)-1, -1, -1):
#     coinsNum += cash//coins[i]
#     cash = cash % coins[i]
#     if cash == 0:
#         break
# print(coinsNum)

############ dp approach ############
# def minimumCoinsNeeded(coins, cash):
#
#     dp = [0] * (cash + 1)
#
#     for i in range(1, cash + 1):
#         for coin in coins:
#             if i - coin >= 0:
#                 if dp[i] == 0:
#                     dp[i] = dp[i - coin] + 1
#                 else:
#                     dp[i] = min(dp[i], dp[i - coin] + 1)
#
#     return dp[cash]
#
# cash = int(input())
# coins = [1, 5, 10, 20, 100]
# print(minimumCoinsNeeded(coins, cash))
#########################################################################

######################################################################### 3
###### Maximum Increase ###### A problem from CodeForces ###### Maximum Increase ######
## tags: dp, greedy, implementation

# n = int(input())
#
# arr = list(map(int, input().split(" ")))
# lens = [1 for i in arr]
#
# for i in range(1, len(arr)):
#     if arr[i] > arr[i-1]:
#         lens[i] += lens[i-1]
#
# print(max(lens))
#########################################################################

######################################################################### 4
###### Fair Division ###### A problem from CodeForces ###### Fair Division ######
## tags: dp, greedy, math

# n = int(input())
#
# for i in range(n):
#     t = int(input())
#     arr = list(map(int, input().split(" ")))
#     ones = arr.count(1)
#     twos = arr.count(2)
#
#     # if there are no cakes with weight 1, then the number of cakes with weight 2 should be even
#     if ones == 0 and twos % 2 == 0:
#         print("YES")
#     elif ones % 2 == 0 and ones != 0:  # only the count of cakes with weight 1 matters
#         print("YES")
#     else:
#         print("NO")
#########################################################################

######################################################################### 5
###### QAQ ###### A problem from CodeForces ###### QAQ ######
## tags: brute force, dp

# str = input()
# n = len(str)
# Qs = [0 for i in range(n+1)]
# As = []
#
# for i in range(n):
#     if str[i] == "Q":
#         # counting the number of Qs from the beginning
#         # to the Ith character of the string
#         Qs[i+1] = Qs[i] + 1
#     else:
#         Qs[i + 1] = Qs[i]
#     if str[i] == "A":
#         # storing the index of A's occurrence in the string
#         As.append(i)
#
# numOfSub = 0
# for j in As:
#     # Qs[n] - Qs[j+1] = the number of Qs from the Ith character
#     # to the end of the string
#     # number of Qs on the left of A * number of the Qs on the right of A == numOfSub
#     numOfSub += Qs[j+1] * (Qs[n] - Qs[j+1])
#
# print(numOfSub)
#########################################################################

######################################################################### 6
###### Last Year's Substring ###### A problem from CodeForces ###### Last Year's Substring ######
## tags: dp, implementation, strings

# t = int(input())
#
# for i in range(t):
#     n = int(input())
#     s = input()
#
#     if s[0:4] == '2020' or s[n-4:n] == '2020':
#         print("YES")
#     elif s[0] == '2' and s[n-3:n] == '020':
#         print("YES")
#     elif s[0:2] == '20' and s[n-2:n] == '20':
#         print("YES")
#     elif s[0:3] == '202' and s[n-1] == '0':
#         print("YES")
#     else:
#         print("NO")
#########################################################################

######################################################################### 7
###### Last minute enhancements ###### A problem from CodeForces ###### Last minute enhancements ######
## tags: dp, greedy

# t = int(input())
#
# for i in range(t):
#     n = int(input())
#     arr = list(map(int, input().split(" ")))
#     counts = [0 for j in range(1, 2 * n + 3)]
#
#     for k in range(len(arr)):
#         if counts[arr[k]] == 0:
#             counts[arr[k]] = 1
#         elif counts[arr[k]] >= 1:
#             arr[k] += 1
#             counts[arr[k]] += 1
#
#     print(len(counts) - counts.count(0))
#########################################################################

######################################################################### 8
###### Alex and a Rhombus ###### A problem from CodeForces ###### Alex and a Rhombus ######
## tags: dp, implementation, math

# n = int(input())
# print(2 * (n ** 2) - 2 * n + 1)
# 1+3+5+...+(2n-3)+(2n-1)+(2n-3)+(2n-5)+...+5+3+1 = n^2 + (n-1)^2
# \--------\  /---------/ \--------\  /---------/
#           \/                      \/
#           n^2                   (n-1)^2
#########################################################################

######################################################################### 9
###### Even Subset Sum Problem ###### A problem from CodeForces ###### Even Subset Sum Problem ######
## tags: brute force, dp, greedy, implementation
## very easy

# def func(arr):
#     prev_odd_num_ind = -1  # index
#
#     for j in range(len(arr)):
#         if arr[j] % 2 == 0:
#             print(1)
#             print(j+1)
#             return
#         if arr[j] % 2 == 1:
#             if prev_odd_num_ind != -1:
#                 print(2)
#                 print(prev_odd_num_ind + 1, j + 1)
#                 return
#             else:
#                 prev_odd_num_ind = j
#
#     print(-1)
#
#
# t = int(input())
#
# for i in range(t):
#     n = int(input())
#     As = list(map(int, input().split(" ")))
#
#     func(As)
#########################################################################

######################################################################### 10
###### The Way to Home ###### A problem from CodeForces ###### The Way to Home ######
## tags: dfs and similar, dp, greedy, implementation

## greedy approach

# def func(n, d, path, p=0):
#     jumps = 0
#
#     while p != n - 1:
#         for i in range(d, -1, -1):
#             if i == 0:
#                 print(-1)
#                 return
#             elif p + i < n - 1 and path[p + i] == '1':
#                 p = p + i
#                 jumps += 1
#                 break
#             elif p + i >= n - 1:
#                 print(jumps + 1)
#                 return
#
#
# n, d = map(int, input().split(" "))
# Path = input()
#
# func(n, d, Path)
#########################################################################

######################################################################### 11
###### Kefa and First Steps ###### A problem from CodeForces ###### Kefa and First Steps ######
## tags: brute force, dp, implementation

## greedy approach

# n = int(input())
# As = list(map(int, input().split(" ")))
#
#
# max_subsegment = 0
# subsegment_len = 1
#
# if n == 1:
#     print(1)
# else:
#     for i in range(1, n):
#         if As[i] >= As[i-1]:
#             subsegment_len += 1
#         else:
#             max_subsegment = max(max_subsegment, subsegment_len)
#             subsegment_len = 1
#
#         if i == n-1:
#             max_subsegment = max(max_subsegment, subsegment_len)
#
#     print(max_subsegment)
#########################################################################

######################################################################### 12
###### New Year's Number ###### A problem from CodeForces ###### New Year's Number ######
## tags: brute force, dp, math


# t = int(input())
#
# for i in range(t):
#     n = int(input())
#
#     while n >= 2020:
#         if n % 2020 == 0:
#             n = 0
#         else:
#             n -= 2021
#
#     if n != 0:
#         print("NO")
#     else:
#         print("YES")
#########################################################################

######################################################################### 13
###### Filling Diamonds ###### A problem from CodeForces ###### Filling Diamonds ######
## tags: brute force, dp, implementation, math
#                                                                                          /\
## very easy problem. prove that you can only have one diamond with this orientation:     /  \ so we choose one from n
#                                                                                         \  /
#                                                                                          \/
# t = int(input())
#
# for i in range(t):
#     n = input()
#     print(n)

#########################################################################

######################################################################### 14
###### Make Product Equal One ###### A problem from CodeForces ###### Make Product Equal One ######
## tags: dp, implementation

# n = int(input())
#
# As = list(map(int, input().split(" ")))
#
# operations_needed = 0
# for j in range(n):
#     if As[j] < 0:
#         operations_needed += -1 - As[j]
#         As[j] = -1
#     elif As[j] > 0:
#         operations_needed += As[j] - 1
#
# c_zero = As.count(0)
# if c_zero == 0:
#     if As.count(-1) % 2 == 1:
#         print(operations_needed + 2)
#     else:
#         print(operations_needed)
# else:
#     print(operations_needed + c_zero)


#########################################################################

######################################################################### 15
###### Love Triangle ###### A problem from CodeForces ###### Love Triangle ######
## tags: graphs

# n = int(input())
# fs = list(map(int, input().split(" ")))
#
# for i in range(n):
#     if fs[fs[fs[i]-1]-1] == i+1:
#         print('YES')
#         break
#     elif i == n-1 and fs[fs[fs[i]-1]-1] != i+1:
#         print("NO")
#########################################################################

######################################################################### 16
###### Non-Substring Subsequence ###### A problem from CodeForces ###### Non-Substring Subsequence ######
## tags: dp, greedy, implementation, strings

## a very good problem ##

# def func(string, Subsequence):
#     if string == Subsequence:
#         return "NO"
#
#     ind_l = 0
#     ind_r = len(string)
#
#     indexes = []
#
#     while Subsequence != "":
#         # searching from right side for the first element of desired Subsequence
#         for k in range(ind_l, ind_r):
#             if string[k] == Subsequence[0]:
#                 indexes.append(k)
#                 ind_l = k+1
#                 Subsequence = Subsequence[1:]
#                 break
#
#         # searching from left side for the last element of desired Subsequence
#         for g in range(ind_r-1, ind_l-1, -1):
#             if len(Subsequence) != 0 and string[g] == Subsequence[len(Subsequence) - 1]:
#                 indexes.append(g)
#                 ind_r = g
#                 Subsequence = Subsequence[: len(Subsequence)-1]
#                 break
#
#     indexes.sort()
#
#     for e in range(len(indexes)-1):
#         if indexes[e] != indexes[e+1] - 1:
#             return "YES"
#
#     return "NO"
#
#
# t = int(input())
#
# for i in range(t):
#     n, q = map(int, input().split(" "))
#     s = input()
#     for j in range(q):
#         l, r = map(int, input().split(" "))
#
#         print(func(s, s[l-1: r]))

#########################################################################

######################################################################### 17
###### Sasha and His Trip ###### A problem from CodeForces ###### Sasha and His Trip ######
## tags: dp, greedy, math

# n, v = map(int, input().split(" "))
# cost = 0
# if v >= n:
#     cost = n-1
# else:
#     cost = v + (n-v-1)*(n-v+2)/2
# print(int(cost))

#########################################################################

######################################################################### 18
###### Napoleon Cake ###### A problem from CodeForces ###### Napoleon Cake ######
## tags: dp, implementation, sorting

# for _ in range(int(input())):
#
#     n = int(input())
#     As = list(map(int, input().split()))
#     drenches = [0] * n
#     ans = 0
#
#     for i in range(n - 1, -1, -1):
#         ans = max(ans - 1, As[i])
#         drenches[i] = int(ans > 0)
#
#     print(*drenches)

#########################################################################

######################################################################### 19
###### New Theatre Square ###### A problem from CodeForces ###### New Theatre Square ######
## tags: brute force, dp, greedy, implementation, two pointers

# for _ in range(int(input())):
#     n, m, x, y = map(int, input().split(" "))
#     costOne = 0  # cost using only 1*1 pave
#     costTwo = 0  # cost also using 1*2 pave
#     finalCost = 0
#     for i in range(n):
#         row = input()
#         countTwos = row.count("..")  # all 1*2 white cells
#         countW = row.count(".")  # all white cells
#         countOnes = countW - 2*countTwos
#         costOne = countW*x
#         costTwo = countTwos*y + countOnes*x
#         finalCost += min(costOne, costTwo)
#     print(finalCost)

#########################################################################

######################################################################### 20
###### PolandBall and Hypothesis ###### A problem from CodeForces ###### PolandBall and Hypothesis ######
## tags: brute force, graphs, math, number theory

    ## number theory appraoch

# n = int(input())
# if n == 1:
#     print(3)
# elif n == 2:
#     print(4)
# else:
#     # m = n-2 => n*(n-2) + 1 = n^2 - 2*n + 1 = (n+1)^2 (m = n+2 is also possible but it violates 1 <= m <= 1000)
#     print(n - 2)

#########################################################################

######################################################################### 21
###### Party ###### A problem from CodeForces ###### Party ######
## tags: dfs and similar, graphs, trees

# n = int(input())
# Ps = []
# for i in range(n):
#     Ps.append(int(input()))
#
# maxLength = 1
# # searching for the longest path
# for i in range(n):
#     if Ps[i] != -1:
#         j = i
#         length = 0
#         # finding the children of the ith element and its children's children and so on, to find the longest path.
#         # the length of the longest path implies the minimum number of groups we need.
#         while j >= 0:
#             j = Ps[j] - 1
#             length += 1
#         maxLength = max(length, maxLength)
# print(maxLength)

#########################################################################

######################################################################### 22
###### Yet Another Card Deck ###### A problem from CodeForces ###### Yet Another Card Deck ######
## tags: brute force, data structures, implementation, trees

# from collections import deque
#
# n, q = list(map(int, input().split(" ")))
# colors = deque(list(map(int, input().split(" "))))
# Qs = list(map(int, input().split(" ")))
#
# for i in Qs:
#     ind = colors.index(i)
#     print(ind + 1, end=' ')
#
#     colors.remove(i)
#     colors.appendleft(i)
#########################################################################

######################################################################### 23
###### Protect Sheep ###### A problem from CodeForces ###### Protect Sheep ######
## tags: brute force, dfs and similar, graphs, implementation

    ## brute force appraoch ##

def check():
    for i in range(R):
        for j in range(C):
            try:
                if j != C - 1 and pasture[i][j] == "S" and pasture[i][j+1] == "W":
                    print("NO")
                    return
                elif j != 0 and pasture[i][j] == "S" and pasture[i][j-1] == "W":
                    print("NO")
                    return
                elif i != R - 1 and pasture[i][j] == "S" and pasture[i+1][j] == "W":
                    print("NO")
                    return
                elif i != 0 and pasture[i][j] == "S" and pasture[i-1][j] == "W":
                    print("NO")
                    return
            except IndexError:
                continue
            if pasture[i][j] == ".":
                pasture[i][j] = "D"
    print("YES")
    for k in range(R):
        print(*pasture[k])


R, C = map(int, input().split(" "))

pasture = []

for _ in range(R):
    pasture.append(list(input()))

check()

#########################################################################