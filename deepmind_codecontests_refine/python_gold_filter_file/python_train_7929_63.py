'''Author- Akshit Monga'''
from sys import stdin,stdout
input = stdin.readline
t=1
for _ in range(t):
    n=int(input())
    a=[int(x) for x in input().split()]
    m= int(input())
    b= [int(x) for x in input().split()]
    print(max(a),max(b))