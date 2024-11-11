#from  sys import stdin
#input=stdin.readline
#a = sorted([(n, i) for i, n in enumerate(map(int, input().split()))])
# from collections import Counter
# import sys
#s="abcdefghijklmnopqrstuvwxyz"
#n=int(input())
#n,k=map(int,input().split())
#arr=list(map(int,input().split()))
#arr=list(map(int,input().split()))
n,x,y=map(int,input().split())
if (x==n//2 or x==(n//2)+1) and (y==n or y==((n//2)+1)):
    print("NO")
else:
    print("YES")
