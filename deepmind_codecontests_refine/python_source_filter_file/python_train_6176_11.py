#===============================================================================================
#importing some useful libraries.
from fractions import Fraction
import sys
import bisect
import heapq
from math import *
from collections import Counter as counter  # Counter(list)  return a dict with {key: count}
from itertools import combinations as comb # if a = [1,2,3] then print(list(comb(a,2))) -----> [(1, 2), (1, 3), (2, 3)]
from itertools import permutations as permutate
from bisect import bisect_left as bl
#If the element is already present in the list,
# the left most position where element has to be inserted is returned.
from bisect import bisect_right as br
from bisect import bisect
#If the element is already present in the list,
# the right most position where element has to be inserted is returned
 
#===============================================================================================
#some shortcuts
 
mod = 1000000007
def inp(): return sys.stdin.readline().strip() #for fast input
def out(var): sys.stdout.write(str(var))  #for fast output, always take string
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
def graph(vertex): return [[] for i in range(0,vertex+1)]
def zerolist(n): return [0]*n
def nextline(): out("\n")  #as stdout.write always print sring.
def testcase(t):
    for p in range(t):
        solve()
def printlist(a) :
    for p in range(0,len(a)):
        out(str(a[p]) + ' ')
def lcm(a,b): return (a*b)//gcd(a,b)
def power(a,b):
    ans = 1
    while(b>0):
        if(b%2==1):
            ans*=a
        a*=a
        b//=2
    return ans


n, m = list(map(int, input().split()))
xc, yc = list(map(int, input().split()))
k = int(input())
a = 0
for i in range(k):
    dx, dy = map(int, input().split())
    #c.append([dx,dy])
    #c.append(dy)
    #d.append(c)
    #c.pop()
    #c.pop()
    l = 0
    r = n
    b = 0
    while(l <= r):
        mid = (l+r)//2
        if(1 <= xc+dx*mid <= n and 1<= yc+dy*mid <= m):
            b = mid
            l = mid+1
        else:
            r = mid-1
    xc = xc+dx*b
    yc = yc+dy*b
    a += b
print(a)

    

    


"""n, a = map(int, input().split())
b = list(map(int, str(n)))
for i in range(a):
    if(b[-1] == 0):
        b.pop()
    else:
        b[-1] = b[-1] - 1
print(''.join(map(str,b)))"""

"""n = int(input())
s = input()
a = list(s)
b = 0
for i in range(n-1):
    if(a[i] == a[i+1]):
        b += 1
print(b)"""

"""s = input()
a = list(s)
b = 1
c = 1
d = 0
e = 0
h = 0
m = 1000000007
if 'c' in a or 'k' in a:
    d = 0
else:
    for i in range(len(a)-1):
        if(a[i] == 'g' and a[i+1] == 'g'):
            b += 1
        if(a[i] == 'f' and a[i+1] == 'f'):
            c += 1
    if(b == 1 and c == 1):
        for i in range(len(a)):
            if(a[i] == 'g'):
                e += 1
            if(a[i] == 'f'):
                h += 1
        if(e == 1 and h == 1):
            d = 1
        else:
            d = e%m + h%m
    elif(b == 1):
        b = 0
        d = b%m + c%m
    elif(c == 1):
        c = 0
        d = b%m + c%m
    else:
        d = b%m * c%m
print(d)
#print(b,c)"""



"""n, k = map(int, input().split())
l = 0
r = n-1
c = 0
while(l <= r):
    m = (l+r)//2
    a = m*(m+1)//2
    b = n-m
    if(a-b == k):
        c = b
        break
    elif(a-b > k):
        r = m-1
    else:
        l = m+1
        #b = a - k
        #print(b,b+m)
        #print(m)
        #if(b+m == n):
            #break
print(c)"""



"""for i in range(int(input())):
    n = int(input())
    a = []
    b = []
    c = n//2
    if(c%2 != 0):
        print("NO")
    else:
        for i in range(1,n+1):
            if(i%2 == 0):
                a.append(i)
        #print(a)
        for i in range(1,a[len(a)-2]):
            if(i%2 != 0):
                b.append(i)
        d = sum(a)-sum(b)
        #print(b)
        if(d%2 != 0):
            b.append(d)
            print("YES")
            print(*(a+b))
        else:
            print("NO")"""
        
            
        


"""for i in range(int(input())):
    n = int(input())
    a = n//2
    s = 8*((a*(a+1)*(2*a+1))//6)
    print(s)"""
    


"""for i in range(int(input())):
    n, s, k = map(int, input().split())
    a = list(map(int, input().split()))
    a = set(a)
    d = 10^5
    e = 10^5
    if s in a:
        b = [x for x in range(1,s)]
        c = [x for x in range(s+1,n+1)]
        c.sort(reverse = True)
        #print(b)
        #print(c)
        if(len(b) == 0):
            for i in range(k):
                if min(c) in a:
                    c.pop()
                    if(len(c) == 0):
                        break
                else:
                    e = min(c)-s
                    break
        elif(len(c) == 0):
            for i in range(k):
                if max(b) in a:
                    b.pop()
                    if(len(b) == 0):
                        break
                else:
                    d = s-max(b)
                    break
        else:
            for i in range(k):
                if max(b) in a:
                    b.pop()
                    if(len(b) == 0):
                        break
                else:
                    d = s-max(b)
                    break
            for i in range(k):
                if min(c) in a:
                    c.pop()
                    if(len(c) == 0):
                        break
                else:
                    e = min(c)-s
                    break
        print(min(d,e))
    else:
        print(0)"""
    
    


"""n = int(input())
m = int(input())
a = []
for i in range(n):
    a.append(int(input()))
kmax = max(a)+m
a.sort()
for i in range(m):
    a[0] = a[0] + 1
    a.sort()
#print(a)
print(max(a), kmax)"""




"""for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = set(a)
    c = 1
    d = []
    a.sort()
    if(len(a) == 1):
        e = 0
    else:
        if(a == list(b)):
            e = 1
        else:
            #for i in range(n):
                #d[a[i]] += 1
            #for i in range(len(d)):
                #if(d[i] > 1 and d[i]%2 == 0):
                    #c += 1
            #print(d)
            for i in range(n-1):
                if(a[i] == a[i+1]):
                    c += 1
                elif(c == 1):
                    pass
                else:
                    d.append(c)
                    c = 1
            if(c>1):
                d.append(c)
            #print(d)
            #if(max(d) == 1):
                #e = 2
            #elif(max(d) == 2):
                #e = max(d)+1
            #else:
            e = max(min(len(b)-1,max(d)),min(len(b),max(d)-1))
    print(e)"""
    
        


"""n, k = map(int, input().split())
l = []
d = 0
for i in range(n):
    a,b = map(int, input().split())
    l.append((a,-b))
#a = sorted(a,key=lambda a: (a[0],a[1]))
l.sort(reverse = True)
#print(l)
c = l[k-1]
#print(c)
for i in range(n):
    if(l[i] == c):
        d += 1
print(d)"""




"""n, k = map(int, input().split())
a = 240
b = a-k
c = 0
d = []
for i in range(1,n+1):
    c += 5*i
    if(b-c >= 0):
        #print(b-c)
        d.append(i)
#print(d)
if(len(d) == 0):
    d.append(0)
print(max(d))"""




"""for i in range(int(input())):
    n = int(input())
    for i in range(2,30):
        b = 2**i - 1
        if(n%b == 0):
            d = n//b
    print(d)"""



"""for i in range(int(input())):
    n, x, m = map(int, input().split())
    a = x
    b = x
    for i in range(m):
        l, r = map(int, input().split())
        if(l <= a <= r):
            a = l
        if(l <= b <= r):
            b = r
    print(b-a+1)"""
    
                
                


"""for i in range(int(input())):
    a, b = map(int, input().split())
    if(a == 0 or b == 0):
        c = 0
    else:
        c = a+b
    d = min(c//3, min(a,b))
    print(d)"""



"""n = int(input())
a = list(map(int, input().split()))
b = 1
e = []
for i in range(n-1):
    if(a[i] == a[i+1]):
        b += 1
    else:
        e.append(b)
        b = 1
e.append(b)
print(e)
h = 0
for i in range(len(e)-1):
    h = max(h,min(e[i],e[i+1]))
print(2*h)"""



"""a, b, c = map(int, input().split())
#e = max(a,b,c)
for i in range(1,a*c):
    if(a*c - i*b <= b*c):
        d = i
        break
print(d)"""



"""for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    b = []
    #b = a[-1] - a[0]
    for i in range(n):
        for j in range(i+1, n):
            b.append(a[j]-a[i])
    print(min(b))"""
     


"""for i in range(int(input())):
    a, b = map(int, input().split())
    if(a<b):
        a, b = b, a
    c = 4*b**2
    if(2*b < a):
        c = a**2
    print(c)"""

    
    


"""n=int(input())
l=[int(i) for i in input().split()]
s=list(input())
sm=0 
for i in range(n):
    if s[i]=='B': 
        sm+=l[i]
        l[i]=-l[i]
print(l)
maxi1=0 
sm1=0 
for i in range(n):
    sm1+=l[i]
    maxi1=max(maxi1,sm1)
sm2=0 
maxi2=0 
for i in range(n-1,-1,-1):
    sm2+=l[i]
    maxi2=max(maxi2,sm2)
print(sm2)
print(maxi1,maxi2)
print(sm+max(maxi1,maxi2))"""


"""n = int(input())
a = list(map(int, input().split()))
b = input()
b = list(b)
d = 0
h = []
l = []
if(n == 1):
    h.append(a[0])
else:
    for i in range(n):
        if(b[i] == 'A'):
            d += 1
    if(d == n):
        h.append(sum(e))
    else:
        for i in range(n-1, -1, -1):
            if(b[i] == 'B'):
                h.append(a[i])
            elif(b[i] == 'A'):
                l.append(a[i])
                #h.append(i+1)
                #break
            else:
                pass
        h.append(max(l))
print(sum(h))"""


        


        
    


"""for i in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = sum(a)
    if(m <= b):
        print(m)
    else:
        print(b)"""
    



"""n = int(input())
a = input()
a = list(a)
b = []
d = 0
e = 1
if(len(a) == 1):
    if(a[0] == '0'):
        e = 0
else:
    for i in range(n):
        if(a[i] == '1'):
            b.append(i)
    if((a[0] == '0' and a[1] == '0') or (a[-1] == '0' and a[-2] == '0')):
        e = 0
    else:
        for i in range(len(b)-1):
            for j in range(b[i], b[i+1]+1):
                #print(j)
                #print(a[j])
                if(a[j] == '0'):
                    d += 1
            #print(d)
            if(d > 2 or d == 0):
                e = 0
                break
            d = 0
if(e == 1):
    print("Yes")
else:
    print("No")

            
#print(b)"""


"""n = int(input())
a = list(map(int, input().split()))
b = 0
d = 0
e = 0
o = 0
g = []
h = []
m = []
for i in range(n):
    if(a[i]<0):
        b += 1
    elif(a[i]>0):
        d += 1
    else:
        e += 1
for i in range(n):
    if(b%2 == 1):
        if(a[i] < 0 and len(g) == 0):
            g.append(a[i])
        elif(a[i] > 0 or a[i] < 0):
            h.append(a[i])
        else:
            m.append(a[i])
    elif(b%2 == 0):
        if(a[i]<0 and len(g) == 0):
            g.append(a[i])
        elif(a[i]<0):
            if(d == 0):
                h.append(a[i])
            else:
                m.append(a[i])
        elif(a[i]>0):
            h.append(a[i])
        else:
            m.append(a[i])
    #if(a[i] == 0):
        #m.append(a[i])
if(d == 0 and len(h)%2 != 0):
    o = h.pop()
    m.append(o)
print(len(g),*g)
print(len(h),*h)
print(len(m),*m)"""
    


"""n, m, k = map(int, input().split())
a = []
b = []
d = 0
e = 0
for i in range(m+1):
    x = int(input())
    a.append(x)
for i in range(m):
    b.append(bin(a[-1]^a[i]).replace("0b",""))
#print(b)
for i in b:
    c = list(i)
    #print(c)
    for j in range(len(c)):
        if(c[j] == '1'):
            d += 1
    #print(d)
    if(d <= k):
        e += 1
    d = 0
        
print(e)
#print(a)"""



"""a, b = map(int, input().split())
c = a+b
d = 0
e = 0
if(a == 0 and b == 0):
    print("NO")
else:
    if(c%2 == 0):
        d = c//2
        e = c//2
    else:
        d = c//2
        e = c//2+1
    if(a == d or a == e and b == e or b == d):
        print("YES")
    else:
        print("NO")"""
    


"""n, m = map(int, input().split())
a = []
b = []
d = []
e = 0
for i in range(n):
    s = input()
    s = list(s)
    a.append(s)
for i in range(len(a)):
    for j in range(i+1, len(a)):
        if(a[i] == a[j][::-1]):
            if(len(b) == 0):
                b.insert(0,''.join(map(str,a[i])))
                b.insert(1,''.join(map(str,a[j])))
            else:
                b.insert(0,''.join(map(str,a[i])))
                b.insert(len(b),''.join(map(str,a[j])))
    #print(b)
    if(len(a[i])%2 == 0):
        if(a[i][:len(a[i])//2] == a[i][len(a[i])//2:][::-1]):
            e = 1
            if(len(d) == 0):
                b.insert(len(b)//2,''.join(map(str,a[i])))
                d.append(''.join(map(str,a[i])))
                #break
            #else:
                #b.insert(0,''.join(map(str,a[i])))
                #d.append(''.join(map(str,a[i])))
    else:
        if(a[i][:len(a[i])//2+1] == a[i][len(a[i])//2:][::-1]):
            e = 1
            if(len(d) == 0):
                b.insert(len(b)//2,''.join(map(str,a[i])))
                d.append(''.join(map(str,a[i])))
                #break
            #else:
                #b.insert(0,''.join(map(str,a[i])))
                #d.append(''.join(map(str,a[i])))
                
print(len(''.join(map(str,b))))
print(''.join(map(str,b)))
#print(d)
#print(e)
#print(a)"""




"""s = input()
s = list(s)
a = []
b = []
d = 0
if(len(s)%2 == 0):
    a.append(s[:len(s)//2])
    b.append(s[len(s)//2:])
else:
    a.append(s[:len(s)//2+1])
    b.append(s[len(s)//2:])
#b = b[::-1]
a = sum(a,[])
b = sum(b,[])
#print(a)
#print(b)
for i in range(len(a)):
    if(a[i] != b[len(a)-i-1]):
        d += 1
        #print(a[i])
        #print(b[len(a)-1-i])
    #else:
        #print(a[i])
        #print(b[len(a)-i-1])
#print(d)
if(d == 1 and len(s)%2 == 0):
    print("YES")
elif(d == 0 and len(s)%2 == 0):
    print("NO")
elif((d == 0 or d == 1) and len(s)%2!=0):
    print("YES")
else:
    print("NO")"""


    
    
    


"""n, k = map(int, input().split())
a = list(map(int, input().split()))
i = 1
while(k-i > 0):
    k -= i
    i += 1

#b = []
#for i in range(1,n+1):
    #b.append(a[0:i])
#b = sum(b,[])
#print(b)
print(a[k-1])"""



"""n = int(input())
a = 0
b = 0
d = n%7
if(d == 0):
    e = n//7
    a = 2*e
    b = 2*e
else:
    if(n<7):
        if(d == 1):
            a = 0
            b = 1
        elif(d > 1 and d < 6):
            a = 0
            b = 2
        else:
            a = 1
            b = 2
    else:
        e = n//7
        a = 2*e
        b = 2*e
        if(d == 1):
            b += 1
        elif(d<6):
            b += 2
        else:
            a += 1
            b += 2
print(a, b)""" 


"""for i in range(int(input())):
    n, m = list(map(int, input().split()))
    a = [[int(x) for x in input().split()] for _ in range(n)]
    r = set()
    c = set()
    #print(a)
    for i in range(n):
        for j in range(m):
            if(a[i][j] == 1):
                r.add(i)
                c.add(j)
    b = min(n-len(r), m-len(c))
    
    if(b%2 == 0):
        print("Vivek")
    else:
        print("Ashish")"""


"""for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    d = 0
    e = 0
    g = 0
    c = sorted(a)
    if(a == c):
        d = 1
    else:
        for i in range(n):
            if(b[i] == 0):
                e += 1
            else:
                g += 1
    if(e and g):
        d = 1
    if(d == 1):
        print("Yes")
    else:
        print("No")"""
    
    
    
    
"""def createMatrix(rowCount, colCount, dataList):   
    mat = []
    for i in range (rowCount):
        rowList = []
        for j in range (colCount):
            if dataList[j] not in mat:
                rowList.append(dataList[j])
        mat.append(rowList)

    return mat 

    
for i in range(int(input())):
    n = int(input())
    r = n
    c = n
    a = [x for x in range(1,n**2+1)]
    m = createMatrix(r,c,a)
    if(n == 2):
        for i in range(n):
            for j in range(n-1):
                if(i%2 != 0):
                    m[i][j], m[i][n-1-j] = m[i][n-1-j], m[i][j]
    else:
        for i in range(n):
            for j in range(n-2):
                if(i%2 != 0):
                    m[i][j], m[i][n-1-j] = m[i][n-1-j], m[i][j]
                #if((m[i][j] + m[n-1-i][n-1-j])%2 != 0):
                    #m[n-1-i][n-1-j], m[n-1-i][n-1-j-1] = m[n-1-i][n-1-j-1], m[n-1-i][n-1-j]
                #else:
                    #m[n-1-i][n-1-j], m[n-1-i][n-1-j-1] = m[n-1-i][n-1-j-1], m[n-1-i][n-1-j]
    for i in range(n):
        for j in range(n):
            print(m[i][j], end=' ')
        print( )"""
    
    
    
    
            
    
    
        


"""for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = 0
    c = 0
    d = 1
    e = 0
    if(len(a) == 1):
        if(a[0] == 5):
            d = 1
        else:
            d = 0
    else:
        #b.append(a[0])
        for i in range(1, n):
            if(a[i] == 10):
                c += 1
                if(b > 0):
                    b = b-1
                else:
                    d = 0
                    break
                #if(a[i] - b <= 5):
                    #b.append(a[i] - sum(b))
                    #b += a[i]-5
            elif(a[i] == 15):
                e += 1
                if(c > 0):
                    c = c-1
                elif(b > 1):
                    b = b-2
                else:
                    d = 0
                    break
            else:
                #b = b + a[i]
                b += 1
                    
        
    #if(e == 0):
        #if(c <= b and c>=1 and b>=1):
            #d = 1
        #else:
            #d = 0
    #else:
        #if(e<=c and c<=b and c>=1 and b>=1):
            #d = 1
        #else:
            #d = 0
    if(d == 1):
        print("YES")
    else:
        print("NO")"""
    
    
    


"""for i in range(int(input())):
    s = input()
    a = 0
    s = list(s)
    j = 1
    for i in range(0, len(s)-1):
    #while(len(s) != 0):
        if(len(s) == 0):
            break
        if((s[i] =='x' and s[i+1] == 'y') or (s[i] == 'y' and s[i+1] == 'x')):
            a += 1
            s[i+1] = 'z'
            #print('a')
            #print(j)
        #else:
            #j -= 1
            #print(j)
            #s.remove(i)
            #s.remove(i+1)
            #if(len(s) == 0):
                #break
    print(a)"""
    
    

"""for i in range(int(input())):
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    a = 0
    for i in range(n):
        if(p[i] > k):
            a += p[i] - k
    print(a)"""


"""for i in range(int(input())):
    ts = int(input())
    a = 0
    b = 0
    if(ts == 1):
        b = 0
    else:
        if(ts%2 != 0):
            a = ts//2+1
            b = ts-a
        else:
            d = 0
            while(ts%2 == 0):
                d += 1
                ts = ts//2
            if(ts%2 != 0):
                a = ts//2+1
                b = ts-a
    print(b)"""
    

"""for i in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    a = []
    c = []
    s.sort()
    for k in range(1,1024):
        for i in s:
            b = i^k
            a.append(b)
        #print(a)
        #print(s)
        if(s == sorted(a)):
            c.append(k)
        a.clear()
    if(len(c) == 0):
        c.append(-1)
    print(min(c))"""
    
            


"""for i in range(int(input())):
    a, b = map(int, input().split())
    c = 0
    if(a == b):
        c = 0
    elif(a > b):
        d = a/b
        if(d == a//b):
            if(d == 1 and a == b):
                c = 0
            elif(d == 2 or d == 4 or d == 8):
                c = 1
            elif(d > 8 and d%2 == 0):
                while(d != 1):
                    if(d%8 == 0):
                        d = d//8
                        c += 1
                    elif(d%4 == 0):
                        d = d//4
                        c += 1
                    elif(d%2 == 0):
                        d = d//2
                        c += 1
                    else:
                        c = -1
                        break
            else:
                c = -1
        else:
            c = -1
    else:
        d = b/a
        if(d == b//a):
            if(d == 1 and b == a):
                c = 0
            elif(d == 2 or d == 4 or d == 8):
                c = 1
            elif(d > 8 and d%2 == 0):
                while(d != 1):
                    if(d%8 == 0):
                        d = d//8
                        c += 1
                    elif(d%4 == 0):
                        d = d//4
                        c += 1
                    elif(d%2 == 0):
                        d = d//2
                        c += 1
                    else:
                        c = -1
                        break
            else:
                c = -1
        else:
            c = -1
    print(c)"""
    
        
        


"""for i in range(int(input())):
    s = input()
    a = list(s)
    d = ['0', '1', '0']
    e = ['1', '0', '1']
    b = 0
    if(len(a) < 3):
        b = 0
    elif(len(a) == 3):
        if(a != d and a != e):
            b = 0
        else:
            b = 1
    else:
        g = 0
        h = 0
        for i in a:
            if(i == '0'):
                g += 1
            else:
                h += 1
        if(g <= 1 or h <= 1):
            b = 0
        if(g < h):
            b = g
        else:
            b = h
    print(b)"""
    
        


"""for i in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    b = 0
    c = 0
    d = 0
    if(len(a) == 1):
        if(a[0]%2 == 0):
            b = 0
        else:
            b = 1
    else:
        for i in a:
            if(i%2 == 0):
                c += 1
            else:
                d += 1
        if(x < c+d):
            if(c and d > 1):
                b = 1
            elif(c == 0 and x%2 == 0):
                b = 0
            elif(d == 0):
                b = 0
            else:
                b = 1
        else:
            #if(x%2 == 0):
            if(d%2 != 0):
                b = 1
            else:
                b = 0
    if(b == 0):
        print("No")
    else:
        print("Yes")"""
    #print(b)
    
            


#import math
"""for i in range(int(input())):
    n, m, k = map(int, input().split())
    c = n//k
    if(m == 0):
        d = 0
    elif(m <= c):
        d = m
    else:
        d = (m-c)//(k-1)
        if((m-c)%(k-1) != 0):
            d += 1
        d = c - d
            #d = c - math.ceil((m-c)/(k-1))
        #else:
            #d = c - 1
        #if(d < 0):
            #d = 0
    print(d)"""


"""def min(n,m):
    if(n%2 == 0 and m%2 == 0):
        b = n*(m//2)
    elif(n%2 == 0 and m%2 != 0):
        b = (n*(m//2))+n//2
    elif(n%2 != 0 and m%2 == 0):
        b = n*(m//2)
    else:
        b = (n*(m//2)) + (n-(n//2))
    return(b)
    


for i in range(int(input())):
    n, m = map(int, input().split())
    print(min(n,m))"""
    



"""from collections import defaultdict

def smallest(s1, s2):
    assert s2 != ''
    d = defaultdict(int)
    nneg = [0]  
    def incr(c):
        d[c] += 1
        if d[c] == 0:
            nneg[0] -= 1
    def decr(c):
        if d[c] == 0:
            nneg[0] += 1
        d[c] -= 1
    for c in s2:
        decr(c)
    minlen = len(s1) + 1
    j = 0
    for i in range(len(s1)):
        while nneg[0] > 0:
            if j >= len(s1):
                return minlen
            incr(s1[j])
            j += 1
        minlen = min(minlen, j - i)
        decr(s1[i])
    return minlen
    
# ans = smallest("12222133333332", "123")
# print(ans)

for i in range(int(input())):
    s1= input()
    e = 0
    g = 0
    h = 0
    for i in range(len(s1)):
        if(s1[i] == '1'):
            e += 1
        elif(s1[i] == '2'):
            g += 1
        elif(s1[i] == '3'):
            h += 1
    s2="123"
    
    if(e < 1 or g < 1 or h < 1):
        ans = 0
    else:
        ans= smallest(s1, s2)
    print(ans)"""


"""for i in range(int(input())):
    a, b, c, d = map(int, input().split())
    r = b
    ans = 0
    if(b < a and c < d):
        ans = -1
    else:
        i = 0
        while(r < a):
            r += c - d
            i += 1
        if(i == 0):
            ans = b
        else:
            ans = b + i*c
    print(ans)           

if(d >= c && a >b)
            cout << -1 << endl;
            continue;
        }
        if(a <= b){
            cout << b << endl;
            continue;
        }
        a -= b;
        long int q = c-d;
        if(a % q == 0)
        {
            cout << ((a/q)*c)+b << endl;
        }else{
            cout << (((a/q)+1)*c)+b << endl;
        }"""
"""for i in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    s.sort()
    c = 0
    p = 1
    if(n == 1):
        c = 1
    else:
        
        for i in range(n):
            if(s[i] <= p):
                c += 1
                p = p - s[i] + 1
            else:
                p = p + 1
    print(c)"""



"""res = False
def chkList(lst):
    if len(lst) < 0 : 
        res = True
    res = all(ele == lst[0] for ele in lst)
    return(res)



for i in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    p = l.copy()
    c = 0
    d = []
    if(chkList(l) == True):
        h = len(l)
    else:
        
        h = len(l)
    print(h)"""


"""for i in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()
    l.reverse()
    #print(l)
    res = 0
    p = 0
    while(True):
        res += 1
        p = p + l[p]
        if(p >= n):
            break
    print(res)"""
    
"""7017173017"""

    

