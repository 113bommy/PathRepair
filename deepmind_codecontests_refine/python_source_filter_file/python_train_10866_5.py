#!/usr/bin/env python
from __future__ import division, print_function
import math
import os
import sys
from fractions import *
from sys import *
from io import BytesIO, IOBase
from itertools import *
from collections import *

# sys.setrecursionlimit(10**5)
M = 10 ** 9 + 7

# print(math.factorial(5))
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
# sys.setrecursionlimit(10**6)

# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")


def inp(): return sys.stdin.readline().rstrip("\r\n")  # for fast input


def out(var): sys.stdout.write(str(var))  # for fast output, always take string


def lis(): return list(map(int, inp().split()))


def stringlis(): return list(map(str, inp().split()))


def sep(): return map(int, inp().split())


def strsep(): return map(str, inp().split())


def fsep(): return map(float, inp().split())


def inpu(): return int(inp())


# -----------------------------------------------------------------

def regularbracket(t):
    p = 0
    for i in t:
        if i == "(":
            p += 1
        else:
            p -= 1
        if p < 0:
            return False
    else:
        if p > 0:
            return False
        else:
            return True


# -------------------------------------------------
def binarySearchCount(arr, n, key):
    left = 0
    right = n - 1

    count = 0

    while (left <= right):
        mid = int((right + left) / 2)

        # Check if middle element is
        # less than or equal to key
        if (arr[mid] <= key):
            count = mid + 1
            left = mid + 1
        # If key is smaller, ignore right half
        else:
            right = mid - 1
    return count


# ------------------------------reverse string(pallindrome)
def reverse1(string):
    pp = ""
    for i in string[::-1]:
        pp += i
    if pp == string:
        return True
    return False


# --------------------------------reverse list(paindrome)
def reverse2(list1):
    l = []
    for i in list1[::-1]:
        l.append(i)
    if l == list1:
        return True
    return False


def mex(list1):
    # list1 = sorted(list1)
    p = max(list1) + 1
    for i in range(len(list1)):
        if list1[i] != i:
            p = i
            break
    return p


def sumofdigits(n):
    n = str(n)
    s1 = 0
    for i in n:
        s1 += int(i)
    return s1


def perfect_square(n):
    s = math.sqrt(n)
    if s == int(s):
        return True
    return False


# -----------------------------roman
def roman_number(x):
    if x > 15999:
        return
    value = [5000, 4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbol = ["F", "MF", "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    roman = ""
    i = 0
    while x > 0:
        div = x // value[i]
        x = x % value[i]
        while div:
            roman += symbol[i]
            div -= 1
        i += 1
    return roman


def soretd(s):
    for i in range(1, len(s)):
        if s[i - 1] > s[i]:
            return False
    return True


# print(soretd("1"))
# ---------------------------
def countRhombi(h, w):
    ct = 0
    for i in range(2, h + 1, 2):
        for j in range(2, w + 1, 2):
            ct += (h - i + 1) * (w - j + 1)
    return ct


def countrhombi2(h, w):
    return ((h * h) // 4) * ((w * w) // 4)


# ---------------------------------
def binpow(a, b):
    if b == 0:
        return 1
    else:
        res = binpow(a, b // 2)
    if b % 2 != 0:
        return res * res * a
    else:
        return res * res


# -------------------------------------------------------
def binpowmodulus(a, b, m):
    a %= m
    res = 1
    while (b > 0):
        if (b & 1):
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res


# -------------------------------------------------------------
def coprime_to_n(n):
    result = n
    i = 2
    while (i * i <= n):
        if (n % i == 0):
            while (n % i == 0):
                n //= i
            result -= result // i
        i += 1
    if (n > 1):
        result -= result // n
    return result


# -------------------prime
def prime(x):
    if x == 1:
        return False
    else:
        for i in range(2, int(math.sqrt(x)) + 1):
            # print(x)
            if (x % i == 0):
                return False
        else:
            return True


def luckynumwithequalnumberoffourandseven(x, n, a):
    if x >= n and str(x).count("4") == str(x).count("7"):
        a.append(x)
    else:
        if x < 1e12:
            luckynumwithequalnumberoffourandseven(x * 10 + 4, n, a)
            luckynumwithequalnumberoffourandseven(x * 10 + 7, n, a)
    return a


def luckynuber(x, n, a):
    p = set(str(x))
    if len(p) <= 2:
        a.append(x)
    if x < n:
        luckynuber(x + 1, n, a)
    return a


# ------------------------------------------------------interactive problems

def interact(type, x):
    if type == "r":
        inp = input()
        return inp.strip()
    else:
        print(x, flush=True)


# ------------------------------------------------------------------zero at end of factorial of a number
def findTrailingZeros(n):
    # Initialize result
    count = 0

    # Keep dividing n by
    # 5 & update Count
    while (n >= 5):
        n //= 5
        count += n

    return count


# -----------------------------------------------merge sort
# Python program for implementation of MergeSort
def mergeSort(arr):
    if len(arr) > 1:

        # Finding the mid of the array
        mid = len(arr) // 2

        # Dividing the array elements
        L = arr[:mid]

        # into 2 halves
        R = arr[mid:]

        # Sorting the first half
        mergeSort(L)

        # Sorting the second half
        mergeSort(R)

        i = j = k = 0

        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1


# -----------------------------------------------lucky number with two lucky any digits
res = set()


def solven(p, l, a, b, n):  # given number
    if p > n or l > 10:
        return
    if p > 0:
        res.add(p)
    solven(p * 10 + a, l + 1, a, b, n)
    solven(p * 10 + b, l + 1, a, b, n)


# problem
"""
n = int(input())
for a in range(0, 10):
    for b in range(0, a):
        solve(0, 0)
print(len(res))
"""


# Python3 program to find all subsets
# by backtracking.

# In the array A at every step we have two
# choices for each element either we can
# ignore the element or we can include the
# element in our subset
def subsetsUtil(A, subset, index, d):
    print(*subset)
    s = sum(subset)
    d.append(s)
    for i in range(index, len(A)):
        # include the A[i] in subset.
        subset.append(A[i])

        # move onto the next element.
        subsetsUtil(A, subset, i + 1, d)

        # exclude the A[i] from subset and
        # triggers backtracking.
        subset.pop(-1)
    return d


def subsetSums(arr, l, r, d, sum=0):
    if l > r:
        d.append(sum)
        return
    subsetSums(arr, l + 1, r, d, sum + arr[l])

    # Subset excluding arr[l]
    subsetSums(arr, l + 1, r, d, sum)
    return d


def print_factors(x):
    factors = []
    for i in range(1, x + 1):
        if x % i == 0:
            factors.append(i)
    return (factors)


# -----------------------------------------------
def calc(X, d, ans, D):
    # print(X,d)
    if len(X) == 0:
        return

    i = X.index(max(X))
    ans[D[max(X)]] = d

    Y = X[:i]
    Z = X[i + 1:]

    calc(Y, d + 1, ans, D)
    calc(Z, d + 1, ans, D)


# ---------------------------------------

def factorization(n, l):
    c = n
    if prime(n) == True:
        l.append(n)
        return l
    for i in range(2, c):
        if n == 1:
            break
        while n % i == 0:
            l.append(i)
            n = n // i
    return l


# endregion------------------------------


def good(b):
    l = []
    i = 0
    while (len(b) != 0):
        if b[i] < b[len(b) - 1 - i]:
            l.append(b[i])
            b.remove(b[i])
        else:
            l.append(b[len(b) - 1 - i])
            b.remove(b[len(b) - 1 - i])
    if l == sorted(l):
        # print(l)
        return True
    return False


# arr=[]
# print(good(arr))
def generate(st, s):
    if len(s) == 0:
        return

    # If current string is not already present.
    if s not in st:
        st.add(s)

        # Traverse current string, one by one
        # remove every character and recur.
        for i in range(len(s)):
            t = list(s).copy()
            t.remove(s[i])
            t = ''.join(t)
            generate(st, t)
    return
#=--------------------------------------------longest increasing subsequence

def largestincreasingsubsequence(A):
    l = [1]*len(A)
    sub=[]
    for i in range(1,len(l)):
        for k in range(i):
            if A[k]<A[i]:
                sub.append(l[k])
        l[i]=1+max(sub,default=0)
    return max(l,default=0)

#----------------------------------longest palindromic substring


"""
def main():
    n,l,a = sep()
    p,f=0,0
    for i in range(n):
            t, v = map(int, input().split())
            p += (t - f) // a
            f = t + v
    print(p + (l - f) // a)
if __name__ == '__main__':
    main()
"""

"""
def main():
    t = inpu()
    for _ in range(t):
        n = int(input())
        cnt = 1
        val = n
        m = n
        for i in range(2, int(n ** (0.5)) + 1):
            ct = 0
            # print(n)
            while (n % i == 0):
                ct += 1
                n //= i
            if ct > cnt:
                cnt = ct
                val = i
        print(cnt)
        for i in range(cnt - 1):
            m //= val
            print(val, end=" ")
        print(m)


if __name__ == '__main__':
    main()
"""
"""
def main():
    t = inpu()
    for _ in range(t):
        n=inpu()
        l = []
        i = 2
        j = 2
        while (i <=n):
            l.append(i)
            j += 3
            i += j
        #print(l)
        if len(l)==0:
            print(0)
            continue
        if l[-1]==n:
            print(1)
        else:
            cnt=0
            l.reverse()
            for i in range(len(l)):
                while(l[i]<=n):
                    #print(l[i],end=" ")
                    cnt+=1
                    n-=l[i]
            #print()
            print(cnt)
if __name__ == '__main__':
    main()
"""
"""
#fun fact: who gave such type of hard question at C please we are in devision 2 come on guys
def main():
    n = inpu()
    s = lis()
    s = sorted(s)
    ayush = [0]*n
    for k in range(1, n):
        for i in range(n - k):
            ayush[i] = min(ayush[i + 1], ayush[i]) + s[i + k] - s[i]
    print(ayush[0])
if __name__ == '__main__':
    main()
"""
"""
def main():
    n=inpu()
    cards = lis()
    cards.sort()
    if len((cards))==1:
        print(-1)
    elif len(set(cards))==1:
        print(1)
        print(cards[0])
    elif len(cards)==2:
        p=(cards[0]+cards[1])
        if p%2==0:
            print(3)
            l = [(p//2),cards[0]-(cards[1]-cards[0]),cards[1]+(cards[1]-cards[0])]
            l.sort()
            print(*l)
        else:
            print(2)
            l = [cards[0]-(cards[1]-cards[0]),cards[1]+(cards[1]-cards[0])]
            l.sort()
            print(*l)
    else:
        d=[]
        for i in range(1, n):
            cc = cards[i] - cards[i - 1]
            d.append(cc)
        d.sort()
        if len(set(d)) == 1:
            if d[0] != 0:
                print(2)
                print(cards[0] - d[0], cards[-1] + d[0])
            else:
                print(1)
                print(cards[0])
            exit()
        if len(set(d)) > 2 or d[-1] != 2 * d[-2]:
            print(0)
        else:
            print(1)
            for i in range(1, n):
                if cards[i] - cards[i - 1] != d[0]:
                    print(cards[i - 1] + d[0])
if __name__ == '__main__':
    main()
"""
"""
def main():
    n = inpu()
    arr = lis()
    p = sorted(arr)
    #print(p)
    cnt=0
    for i in range(n):
        if arr[i]!=p[i]:
            cnt+=1
    if cnt<3:
        print("YES")
    else:
        print("NO")
if __name__ == '__main__':
    main()
"""
"""
def main():
    def dfs(x, y, visited, s):
        visited[s] = True
        #print(x[s],y[s])
        for i in range(n):
            if visited[i] == False and (x[s] == x[i] or y[s] == y[i]):
                dfs(x, y, visited, i)
    n = inpu()
    x = []
    y = []
    c = -1
    visited = [False] * n
    for _ in range(n):
        a, b = sep()
        x.append(a)
        y.append(b)
    for j in range(n):
        if visited[j] == False:
            dfs(x, y, visited, j)
            c+=1
    print(c)
if __name__ == '__main__':
    main()
"""
"""
def main():
    s = inp()
    nb,ns,nc = sep()
    pb,ps,pc = sep()
    r = inpu()
    cb = s.count("B")
    cs = s.count("S")
    cc = s.count("C")
    l,h = 0,10**13
    while l+1<h:
        x = (h + l) // 2
        #print(x)
        fx = ((max(0, cb * x - nb) * pb) + (max(0, cs * x - ns) * ps) + (max(0, cc * x - nc) * pc))
        if fx > r:
            h = x
        else:
            l = x
    print(l)
if __name__ == '__main__':
    main()
"""
"""
def main():
    n=inpu()
    if n==1:
        print(0)
        exit()
    l=[]
    for i in range(n):
        a = lis()
        l.append(a)
    cnt=0
    l.sort()
    print(l)
    a = l[0][0]
    b = l[0][1]
    for i in range(n):
            if l[i][0]>a and l[i][1]<b:
                cnt+=1
            else:
                a=l[i][0]
                b=l[i][1]
    print(cnt)
if __name__ == '__main__':
    main()
"""
"""
#print(prime(1357477777797))
def main():
    n,k = sep()
    l=[]
    if k<n//2:
        print(-1)
        exit()
    if n==1 and k==0:
        print(1)
        exit()
    if n==1:
        print(-1)
        exit()
    for i in range(n):
        l.append(10**9-i)
    k = k-n//2+1
    l[0]=k
    l[1]=k*2
    print(*l)
if __name__ == '__main__':
    main()
"""
dp = [0] * 1000001
ap = [0] * 1000001
def fun(arr,n):
    for i in range(n-1,0,-1):
        if arr[i]>arr[i+1]:
            dp[i]=1+dp[i+1]
    for i in range(n-1,0,-1):
        if arr[i]<=arr[i+1]:
            ap[i]=1+ap[i+1]

def main():
    n,m = sep()
    arr = lis()
    arr.insert(0,0)
    fun(arr,n)
    for _ in range(m):
        u,v = sep()
        x = u + ap[u] + dp[u + ap[u]]
        if x>=v:
            print("Yes")
        else:
            print("No")
if __name__ == '__main__':
    main()
