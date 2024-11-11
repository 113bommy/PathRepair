'''Author- Akshit Monga'''
from sys import stdin, stdout
input = stdin.readline
t = int(input())
for _ in range(t):
    temp=input()
    a,b=map(int,input().split())
    c,d=map(int,input().split())
    e,f=map(int,input().split())
    ans=abs(a-c)+abs(b-d)
    if a==c==e and (b<f<d or d<f<b):
        ans+=2
    if b==d==f and (a<e<c or c<e<a):
        ans+=2
    print(ans)