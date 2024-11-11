# -*- coding: utf-8 -*-
"""
Created on Sun Nov 24 22:40:58 2019

@author: lfy
"""

"""domino"""
def main():
    a=input().split(" ")
    
    l=int(a[0])
    w=int(a[1])
    l1=l//2
    n=l1*w+(w%2)//2
    print(n)
    
if __name__=="__main__":
    main()
    