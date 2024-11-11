#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 30 15:22:04 2020

@author: yash
"""

#      _       _       _                     _         _     _                 
#     | | __ _(_)  ___| |__  _ __ ___  ___  | | ___ __(_)___| |__  _ __   __ _ 
#  _  | |/ _` | | / __| '_ \| '__/ _ \/ _ \ | |/ / '__| / __| '_ \| '_ \ / _` |
# | |_| | (_| | | \__ \ | | | | |  __/  __/ |   <| |  | \__ \ | | | | | | (_| |
#  \___/ \__,_|_| |___/_| |_|_|  \___|\___| |_|\_\_|  |_|___/_| |_|_| |_|\__,_|

"""
# Codeforces Round #163 (Div. 2), problem: (B) Queue at the School,                                                                            
        n, t = map(int, input().split())
        p = input()
        s = list(p)
        for i in range(t):
            j = 0
            while j < len(s)-1:
                if s[j] == 'G':
                    j += 1
                elif s[j] != s[j+1]:
                    s[j], s[j+1] = s[j+1], s[j]
                    j += 2
                else:
                    j += 1
        print(''.join(s))
        
# B G G B G
# G B G G B

# B G G B G --> G B G G B --> G G B G B
"""

"""
# contest: Codeforces Round #197 (Div. 2), problem: (B) Xenia and Ringroad 
    Case - 1:
       4 3
       3 2 3
     
       1->3 : 1->2->3
       3->2 : 3->4->1->2
       2->3 : 2->3
       
   
   
    n, m = map(int, input().split())
    initial_pos = 1
    ans = 0
    x = list(map(int, input().split()))
    for i in x:
        ans += ((i-initial_pos+n)%n)
        initial_pos = i
    print(ans)
"""

"""
# Codeforces Round #267 (Div. 2), problem: (B) Fedor and New Game
    n,m,k = map(int,input().split())
    a = []
    cnt = 0
     
    for i in range(0,m):
        x = int(input())
        a.append(x)
    f = int(input())
     
    for i in range(0,m):
        if bin(a[i]^f).count('1') <= k:
            cnt += 1
     
    print(cnt)
"""

"""
# Codeforces Round #273 (Div. 2), problem: (B) Random Teams
    n,m=map(int,input().split())
    a=n//m
    max_pairs = (n-m+1)*(n-m)//2
    min_pairs = m*a*(a-1)//2 + a*(n%m)
    print(min_pairs ,max_pairs)
"""

"""
 # Codeforces Round #258 (Div. 2), problem: (B) Sort the Array
        n = int(input())
        l = list(map(int, input().split()))
        startIdx = 0
        endIdx = 0
        i = 0
        while i < len(l)-1:
            if l[i] > l[i+1]:
                startIdx = i+1
                j = i
                while j < len(l) - 1 and l[j] > l[j+1]:
                    j+=1
                endIdx = j+1
                i += j
            i+=1
        
        temp = list(l)
        x = startIdx
        y = endIdx
        while startIdx < endIdx:
            temp[startIdx-1], temp[endIdx-1] = temp[endIdx-1], temp[startIdx-1]
            startIdx += 1
            endIdx -= 1
        if x != y:   
            l.sort()
            if temp == l:
                print("yes")
                print(x, y)
            else:
                print("no")
        else:
            print("yes")
            print(1, 1)
"""
"""
# Codeforces Round #284 (Div. 2), problem: (B) Lecture
        n, m = map(int, input().split())
        dic = {}
        for i in range(m):
            x, y = map(str, input().split())
            if len(x) < len(y):
                dic[y]=x
            elif len(x) > len(y):
                dic[x]=y
            else:
                dic[y]=x
        content = input()
        l = list(content.split(" "))
        ans = ''
        for i in l:
            try:
                if len(i) > len(dic[i]):
                    ans += dic[i]
                    ans += ' '
                else:
                    ans += i
                    ans += ' '
            except:
                ans += i
                ans += ' '         
        print(ans)
        
            OR
        
        

        n, m = map(int, input().split())
        d = {}
         
        for i in range(m):
          a, b = input().split()
          d[a] = b if len(b) < len(a) else a
         
        for i in input().split():
          print(d[i], end = " ")
          
          
              OR(My solution optimal version)
              
        
        n, m = map(int, input().split())
        dic = {}
        ans = ''
        for i in range(m):
            x, y = map(str, input().split())
            if len(x) > len(y):
                dic[x]=y
            else:
                dic[x]=x
        for i in input().split():
            ans += dic[i]
            ans += ' '
        
        print(ans)
        
 """   
# def SieveOfEratosthenes(n, k):
#     prime = [True for i in range(n+1)]
#     p = 2
#     while(p*p <= n):
#         if prime[p] == True:
#             for i in range(p*p, n+1, p):
#                 prime[i] = False
#         p += 1
    
#     for p in range(2, n+1):
#         if prime[p] and p*p <= k and p*p == k:
#             return "YES"
#     return "NO"
        
    
    
# n = int(input())
# l = list(map(int, input().split()))
# for i in l:
#     print(SieveOfEratosthenes(n, i))




"""
 # Codeforces Round #288 (Div. 2), problem: (B) Anton and currency you all know
    n = input()
    l = list(n)                  # 4 3 8 2 5
    index = float("-inf")
    for i in range(len(l)):
        if int(l[i])%2 == 0:
            if l[-1] < l[i]:
                index = max(index, i)
            else:
                index = i 
                break
                
    if index != float("-inf"):
        l[index],l[-1]=l[-1],l[index]
        print(''.join(l))
    else:
        print(-1)

"""



"""
 # Codeforces Round #FF (Div. 2), problem: (B) DZY Loves Strings
        s = input()
        k = int(input()) 
        l = list(map(int, input().split()))
        dic = {}
        max_val = max(l)
        count = 0
        for i in 'abcdefghijklmnopqrstuvwxyz':
            dic[i] = l[count]
            count += 1
        ans = 0
        for i in range(len(s)):
            j = i+1
            ans = ans + j*dic[s[i]]
        
        i = len(s)+1
        while i < len(s)+1+k:
            ans = ans + i*max_val
            i += 1
        print(ans)
        
          OR 
          
        s = input()
        k = int(input()) 
        l = list(map(int, input().split()))
        max_val = max(l)
        count = 0
        ans = 0
        for i in range(len(s)):
            j = i+1
            ans = ans + j*l[ord(s[i])-ord('a')]     
        i = len(s)+1
        while i < len(s)+1+k:
            ans = ans + i*max_val
            i += 1
        print(ans)
"""


"""
# Codeforces Round #287 (Div. 2), problem: (B) Amr and Pins
        import math
        r, x1, y1, x2, y2 = map(int, input().split())
        Distance = math.sqrt((x2-x1)**2 + (y2-y1)**2)
        ans = math.ceil(Distance/(2*r))
        print(ans)
"""
"""
# Codeforces Round #259 (Div. 2), problem: (B) Little Pony and Sort by Shift
        def solve():
            n = int(input())
            l = list(map(int, input().split()))
            flag = True
            ans = True
            pos = 0
            val = 0
            if n == 2 and l[0] < l[1]:
                return 0
            if len(set(l)) == 1:
                return 0
            for i in range(len(l)-1):
                if flag:
                    if l[i] > l[i+1]:
                        flag = False
                        pos = i+1
                else:
                    if l[i] > l[i+1]:
                        ans = False
            
            if l[0]<l[-1]:  #3 4 1 2 3 5
                ans = False
            if not flag and ans:
                val = n-pos
                return val
            else:
                return -1
        
        print(solve())
    
# 4 5 1 2 3
# 3 4 5 1 2  step - 1
# 2 3 4 5 1  step - 2
# 1 2 3 4 5  step - 3

"""


"""
# Given: x,y
# f1 = x
# f2 = y
# fi = f(i-1) + f(i+1)
# To find f3? --> f2 = f1 + f3
# ------------

# f3 = f2 - f1 = y-x
# f4 = f3 - f2 = y - x - y = -x
# f5 = f4 - f3 = -x - y + x = -y
# f6 = f5 - f4 = -y - (-x) = x-y
# f7 = f6 - f5 = x - y -  (-y) = x
# f8 = f7 - f6 = x - x + y = y

x, y = map(int, input().split())
n = int(input())
l = [x-y, x, y, y-x, -x, -y]
print(l[n%6]%1000000007)
"""


"""
n = int(input())
l = []
for i in range(n):
    val = int(input())       
    l.append(val)
ans = n + (n-1)
ans += l[0]
for i in range(1, len(l)):
    ans += abs(l[i]-l[i-1])
print(ans)
"""
"""
n, s, t = map(int, input().split())
l = list(map(int, input().split()))
for i in range(n):
    if s == t:
        print(i)
        exit()
    s = l[s-1]
print(-1)
"""


"""
# Codeforces Round #256 (Div. 2), problem: (B) Suffix Structures
s = input()
t = input()

sorted_s = sorted(s)
sorted_t = sorted(t)
def subset(t, s):
    i = 0
    for char in s:
        if(char == t[i]):
            i += 1
        if(i == len(t)):
            break
    return i == len(t)
    
if sorted_t == sorted_s:
    print("array")
elif subset(t,s):
    print("automaton")
elif subset(sorted_t, sorted_s):
    print("both")
else:
    print("need tree")

"""
    

# array = []
# for i in range(3):
#     row = list(map(int, input().split()))
#     array.append(row)
# array[0][0] = 99999
# row_sum = sum(array[0])
# for i in range(1, 3):
#     for j in range(3):
#         if i == j:
#             array[i][j] = row_sum - sum(array[i])

# for i in range(3):
#     print(*array[i])



# import math
# for _ in range(int(input())):
#     n, x = map(int, input().split())
#     l = list(map(int, input().split()))
#     minimum = 0
#     maximum = 0
#     min_ = sum(l)//x
#     max_tre = False
#     for i in range(len(l)):
#         if l[i]%x != 0:
#             max_tre = True
#         maximum += math.ceil(l[i]/x)
#     if max_tre:
#         print(min_, maximum)
#     else:
#         print(maximum, min_)
        

# for _ in range(int(input())):
#     n, x = map(int, input().split())
#     l = list(map(int, input().split()))
#     ans = 0
#     for i in range(len(l)):
#         if l[i]%x == 0:
#             l.append(l[i]//x)
#             ans += ((x-1)*(l[i]//x))
#         else:
#             ans += l[i]
            
#     print(ans)
            
# 2 2 4


# # 2 2 4 1 2   1 2   




"""
x 3 6
5 y 5
4 7 z

x + y + z = x + 3 + 6        
y + z = 9  -----(1)
10 + y = 11 + z
y - z = 1 ------(2)
Adding (1) and (2), we get-->
2y = 10
y = 5
z = 4
x = 6

---------------

z = arr[0][1] + arr[0][2] - y
arr[1][0] + y + arr[1][2] = arr[2][0] + arr[2][1] + z
arr[1][0] + y + arr[1][2] = arr[2][0] + arr[2][1] + arr[0][1] + arr[0][2] - y
2y = arr[2][0] + arr[2][1] + arr[0][1] + arr[0][2] - arr[1][0] - arr[1][2]
y = (arr[2][0] + arr[2][1] + arr[0][1] + arr[0][2] - arr[1][0] - arr[1][2])/2
z = arr[1][0] + arr[1][2] - arr[2][0] -  arr[2][1] + y
x = arr[2][0] + arr[2][1] + z - arr[0][1] - arr[0][2]

"""
"""
arr = []
for _ in range(3):
    l = list(map(int, input().split()))
    arr.append(l)
    
y = 0
x = 0
z = 0
y = (arr[2][0] + arr[2][1] + arr[0][1] + arr[0][2] - arr[1][0] - arr[1][2])//2
z = arr[1][0] + arr[1][2] - arr[2][0] -  arr[2][1] + y
x = arr[2][0] + arr[2][1] + z - arr[0][1] - arr[0][2]

arr[0][0] = x
arr[1][1] = y
arr[2][2] = z

for i in range(3):
    print(*arr[i])

"""

def solve(l, n, m):   # 2 3 4 5 6 7 8 9 10
    l.sort()
    count = 1
    for i in range(1, m):
        if l[i] - l[i-1] == 1:
            count += 1
        else:
            count = 1
        if count > 2:
            return "NO"
    return "YES"
        
    
    
n, m = map(int, input().split())
if m > 0:
    l = list(map(int, input().split()))
if m == 0:
    print("YES")    
elif (1 in l) or (n in l):
    print("NO")
else:
    print(solve(l, n, m))





































        
        
