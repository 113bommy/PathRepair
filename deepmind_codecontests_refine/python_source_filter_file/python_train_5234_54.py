import sys
from sys import stdin
import math
#Find Set LSB = (x&(-x)), isPowerOfTwo = (x & (x-1))
def iinput():
    return int(input())
def minput():
    return map(int,input().split())
def linput():
    return list(map(int,input().split()))

def fiinput():
    return int(stdin.readline())
def fminput():
    return map(int,stdin.readline().strip().split())
def flinput():
    return list(map(int,stdin.readline().strip().split()))

for _ in range(iinput()):
    n,s=input().split()
    s=int(s)
    ss=0
    n=list(n)
    for i in range(len(n)):
        ss+=int(n[i])
    if(ss<=s):
        print(0)
    else:
        n=n[::-1]
        n.append('0')
        # print(n)
        c=0
        i=0
        while(ss>s):
            ss-=int(n[i])
            
            if(int(n[i])!=0):
                c+=10**(i+1)-int(n[i])*(10**(i))
                n[i]='0'
                # print(ord(n[i+1]))
                if(n[i+1]!='9'):
                    n[i+1]=chr(ord(n[i+1])+1)
                else:
                    n[i+1]='0'
                    ss-=9
                    while(n[i+2]=='9'):
                        ss-=9
                        n[i+2]='0'
                        i+=1
                        ss-=9
                    # n[i+2]='1'
                    # ss-=9
                    n[i+2]=chr(ord(n[i+2])+1)
            # elif(int(n[i])!=0):
            #     n.append("1")
            #     n[i]="0"
                ss+=1
            i+=1
            # print(n)
        print(c)
    