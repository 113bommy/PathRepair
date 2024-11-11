# -*- coding: utf-8 -*-
"""
Created on Sun Oct 29 00:04:11 2017

@author: Paras
"""

a=int(input())
slot1=[]
slot2=[]
slot3=[]
slot4=[]
slot5=[]
slot6=[]
slot7=[]
for i in range(a):
    b=input()
    slot1.append(int(b[0]))
    slot2.append(int(b[2]))
    slot3.append(int(b[2]))
    slot4.append(int(b[3]))
    slot5.append(int(b[4]))
    slot6.append(int(b[5]))
    slot7.append(int(b[6]))
print(max(sum(slot1),sum(slot2),sum(slot3),sum(slot4),sum(slot5),sum(slot6),sum(slot7)))