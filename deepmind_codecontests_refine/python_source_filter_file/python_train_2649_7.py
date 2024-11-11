'''
Created on 2016年3月3日

@author: HaoGe
'''
n,x=map(int, input().split())
c_list=list(map(int,input().split()))
c_list.sort()
sum=0
for i in c_list:
    sum+=i*x
    x=max(x-1,i)
print(sum)