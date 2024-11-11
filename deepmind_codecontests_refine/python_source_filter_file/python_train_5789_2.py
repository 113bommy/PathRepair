from sys import *
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
l3=list(map(int,input().split()))
l4=list(map(int,input().split()))
if l1[-1]:
    if sum(l1[:-1]) or l4[2] or l2[0] or l3[1]: print("YES"); exit()
if l2[-1]:
    if sum(l2[:-1]) or l1[2] or l4[1] or l3[0]: print("YES"); exit()
if l3[-1]:
    if sum(l3[:-1]) or l2[2] or l1[1] or l3[0]: print("YES"); exit()
if l4[-1]:
    if sum(l4[:-1]) or l3[2] or l2[1] or l1[0]: print("YES"); exit()
print("NO")