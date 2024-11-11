# -*- coding: utf-8 -*-
"""
Created on Mon Oct  5 23:00:42 2020

@author: Dark Soul
"""
def nextPermutation(nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        #http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
        i = j = len(nums)-1
        while i > 0 and nums[i]<=nums[i-1]:
            i-=1
        i-=1
        if i<0:
            nums.reverse()
            return
        
        while j>i and nums[j]<=nums[i]:
            j-=1
        
        nums[i],nums[j] = nums[j], nums[i]
        
        k,l = i+1, len(nums)-1
        
        while k<l:
            nums[k],nums[l] = nums[l], nums[k]
            k+=1
            l-=1
s=list(input(''))
l=len(s)
if l%2:
    l+=1
    k=l
    l//=2
    ans='4'*l+'7'*l
    if k%2:
        ans='4'+ans
    
    print(ans)
else:
    l=l//2
    ans='4'*l+'7'*l
    ans=list(ans)
    itera=0
    flag=0
    while ans<s:
        nextPermutation(ans)
        itera+=1
        if itera>(2**(2*l)):
            flag=1
            break
    
    sol=''.join(ans)
    if flag:
        l+=1
        sol='4'*(l)+'7'*l
    print(int(sol))
    

        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        