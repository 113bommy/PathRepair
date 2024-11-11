# Python program to display all the prime numbers within an interval
import math
n = int(input(""))

for i in range(0, n):
       f = int(input(""))
       inp = list(map(int,input().split()))
       sum = 0
       count=0
       for k in range(0,len(inp)):
           
           if inp[k]%2!=0:
               sum+=inp[k]
               count+=1
       if count%2!=0 or count<f:
           print("YES")
       else:
           print("NO")
