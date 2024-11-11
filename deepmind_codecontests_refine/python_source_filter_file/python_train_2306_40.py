#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue
sys.setrecursionlimit(1000000)
#sys.stdin = open("input.txt", "r")

n = int(input())
a = list(map(int, input().split()))
print(2+a[2]^min(a))