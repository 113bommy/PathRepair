#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Nov  6 21:38:03 2018

@author: supaul
"""

# your code goes here
n=int(input())
var1=[int(x) for x in input().split()]
m=int(input())
var2=[int(x) for x in input().split()]
var1=sorted(var1)
var2=sorted(var2)
index1=0
index2=0
cont=0
while(index1<n and index2<m):
	if(var1[index1]+1==var2[index2] or var1[index1]==var2[index2] or var1[index1]+1==var2[index2]):
		cont+=1
		index1+=1
		index2+=1
		#print("I am here ",index1,index2)
	elif(var1[index1]<var2[index2]):
		index1+=1
		#print("I am here ",index1,index2)
	else:
		index2+=1
		#print("I am here ",index1,index2)
print(cont)
	