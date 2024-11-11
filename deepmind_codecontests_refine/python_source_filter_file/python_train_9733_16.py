import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 


n=iinput()
min1,max1=rinput()
min2,max2=rinput()
min3,max3=rinput()

if(min1+min2+min3==n):
    print(min1,min2,min3)
elif(max1+max2+max3==n):
    print(max1,max2,max3)
else:
    while(min1+min2+min3!=n):
        while(min1<=max1 and min1+min2+min3!=n):
            min1+=1
        while(min2<=max2 and min1+min2+min3!=n):
            min2+=1
        while(min3<=max3 and min1+min2+min3!=n):
            min3+=1
    print(min1,min2,min3)