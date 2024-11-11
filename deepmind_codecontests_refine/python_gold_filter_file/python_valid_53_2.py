from sys import stdin,stdout
def INPUT():return list(int(i) for i in stdin.readline().split())
def inp():return stdin.readline()
def out(x):return stdout.write(x)
import math
INT_MAX=10**13
from bisect import bisect_left
import sys
MOD=10**9+7
inf=MOD**2
from decimal import*
#===================================================================
# import kivy
# from kivy.app import App
# from kivy.uix.label import Label
#
# class A(App):
#     def build(self):
#         return Label(text="Hello ")
# if __name__=='__main__':
#     A().run()

for _ in range(int(input())):
    n,k=map(int,input().split())
    A=INPUT()
    B=A.copy()
    B.sort()
    D={}
    for i in range(n):
        D[A[i]]=i
    count=1
    for i in range(1,n):
        if D[B[i]]-D[B[i-1]]!=1:
            count+=1
    if count<=k:
        print("Yes")
    else:
        print("No")
    #print()
