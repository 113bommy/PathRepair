# -*- coding: utf-8 -*-
"""
Created on Thu May 14 21:57:12 2020

@author: Kashem Pagla
"""


for _ in range(int(input())):
    n=int(input())
    k=n//2; ans=8;x=0
    for i in range(1,k+1):
        x+=ans*i
        ans+=8
    print(0 if n<3 else x)    