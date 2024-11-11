import math
import copy
from decimal import*
# import sys
# input = sys.stdin.buffer.readline

def check(str,str1):
    # print(str,str1)
    i=0
    j=0
    ans=0
    while i<len(str) and j<len(str1):
        if str[i]==str1[j]:
            i+=1
            j+=1
        else:
            i+=1
            ans+=1
    return ans+len(str)-i+len(str1)-j

def solve():
    t=1
    t=int(input())
    for _ in range(t):
        a=[]
        a.append(1)
        ans=1
        for i in range(1,60):
            ans*=2
            a.append(ans)
        # print(a)
        n=int(input())
        # a,b,c=map(int,input().split())
        # a=list(map(int,input().split()))
        # h=list(map(int,input().split()))
        # g=list(map(int,input().split()))
        
        for i in range(1,60):
            ans=min(ans,check(str(n),str(a[i])))
        print(ans)

if __name__=="__main__":
    solve()



# print("{:.8f}".format(max(0,ans))) -> this print 8 digit after point 
# copy  list to another  list--> b=copy.deepcopy(a) 