#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep  8 16:09:29 2020

@author: anirudhasarmatumuluri
"""

def main():
    n = int(input())
    if n==10 or n>21:
        print(0)
        return
    if n==21:
        print(4)
        return
    if n==20:
        print(15)
        return
    else:
        print(4)
    
    return




main()