import sys
import math
#input=sys.stdin.readline
def longest_pal(s):
    kmp=s+"#"+s[::-1]
    lps=[0]*(len(kmp))
    n1=len(kmp)
    for i in range(1,n1):
        prev_idx = lps[i - 1]
        while prev_idx>0 and kmp[i]!=kmp[prev_idx]:
            prev_idx = lps[prev_idx - 1]
            
        if kmp[i]==kmp[prev_idx]:
            lps[i]=prev_idx+1
        else:
            lps[i]=prev_idx
    #print(lps,kmp)
    return lps[n1-1]
    
t=int(input())
#t=1

for _ in range(t):
    s=input()
    maxi1=longest_pal(s)
    maxi2=longest_pal(s[::-1])
    #print(maxi1,maxi2)
    n=len(s)
    #print(s)
    i,j,maxi=0,n-1,0
    while i<j:
        if s[i]==s[j]:
            i+=1
            j-=1
            maxi+=1
        else:
            break
    #print(s,i,j)
    maxi3=longest_pal(s[i:j+1])
    maxi4=longest_pal(s[j:i-1:-1])
    #print(s[i:j+1],maxi3,maxi4,s[j:i-1:-1])
    #l=list(map(int,input().split()))
    #s=input()
    if max(maxi1,maxi2)>2*maxi+max(maxi3,maxi4):
        if maxi1>maxi2:
            print(s[:maxi1])
        else:
            print(s[n-maxi2:])
    else:
        if maxi3>maxi4:
            print(s[:i]+s[i:i+maxi3]+s[j+1:])
        else:
            print(s[:i]+s[j+1-maxi4:j+1]+s[j+1:])
    