# -*- coding: utf-8 -*-
"""
Created on Thu Nov  4 00:34:36 2021

@author: Yogesh Panjwani
"""
t=int(input())
for _ in range(t):
    x0 , n = map(int, input().split())
    final= 0
    val=0
    if n==0:
        print(x0)
        continue
    
    ans = x0
    if x0%2==0:
        ans-=1
        pair = (n-1)//4
        ans -= 4*pair
        r = (n-1)%4
        if r==1:
            ans += n
        elif r==2:
            ans += (n+n-1)
        elif r==3:
            ans += (n+n-1+n-2)
        
        print(ans)
        
    else:
        ans+=1
        pair = (n-1)//4
        ans += 4*pair
        r = (n-1)%4
        if r==1:
            ans -= n
        elif r==2:
            ans -= (n+n-1)
        elif r==3:
            ans -= (n+n-1+n-2)
            
        print(ans)