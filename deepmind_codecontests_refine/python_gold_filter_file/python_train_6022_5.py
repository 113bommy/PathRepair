import sys
import bisect
input = sys.stdin.readline
num=0
n=int(input())
top=list(map(int,input().split()))
mid=list(map(int,input().split()))
und=list(map(int,input().split()))
top.sort()
mid.sort()
und.sort()
for i in mid:
    a=bisect.bisect_left(top,i)
    c=n-bisect.bisect_right(und,i)
    num+=a*c
print(num)