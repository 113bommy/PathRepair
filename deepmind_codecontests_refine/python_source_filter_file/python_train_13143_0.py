#!/usr/bin/env python3

import heapq
import sys
input=sys.stdin.readline

def shift(k,arr):
    arr[k],arr[k+1],arr[k+2]=arr[k+2],arr[k],arr[k+1]

def solve(pos,cnt,ans,arr):
    n=len(arr)
    q=[]
    for i in range(n):
        heapq.heappush(q,arr[i])
    while pos<n-2:
        tmp=heapq.heappop(q)
        if arr[pos]==tmp:
            pos+=1
            continue
        else:
            tpos=pos+arr[pos:].index(tmp)
            while tpos-pos>=2:
                cnt+=1
                tpos-=2
                ans.append(tpos+1)
                shift(tpos,arr)
            if tpos-pos==1:
                cnt+=2
                tpos-=1
                ans.append(tpos+1)
                ans.append(tpos+1)
                shift(tpos,arr)                
                shift(tpos,arr)
            pos+=1
    return cnt,ans

t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    cnt,ans=solve(0,0,[],arr)
    if arr[n-2]>arr[n-1]:
        print(cnt)
        print(*ans)
    else:
        ttpos=-1
        for i in range(n-2,-1,-1):
            if arr[i]==arr[i+1]:
                ttpos=i
                break
        if ttpos!=-1:
            cnt+=2
            ans.append(ttpos+1)
            ans.append(ttpos+1)            
            shift(ttpos,arr)
            shift(ttpos,arr)
            cnt,ans=solve(0,cnt,ans,arr)
            print(cnt)
            print(*ans)
        else:
            cnt+=1
            ans.append(n-2)
            shift(n-3,arr)
            if arr[n-3]<=arr[n-2]<=arr[n-1]:
                print(cnt)
                print(*ans)
            else:
                cnt+=1
                ans.append(n-2)
                shift(n-3,arr)
                if arr[n-3]<=arr[n-2]<=arr[n-1]:
                    print(cnt)
                    print(*ans)
                else:
                    print(-1)