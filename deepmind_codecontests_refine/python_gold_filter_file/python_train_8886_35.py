# -*- coding: utf-8 -*-
n_stone=input()
color_stone=input()
stone=list(color_stone)
n_stone=int(n_stone)
ans=0
for i in range(n_stone-1):
    if stone[i]==stone[i+1]:
        ans+=1
print(ans)