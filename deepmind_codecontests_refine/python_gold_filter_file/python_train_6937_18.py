#!/bin/python3

import sys

def solution(tabs, pointer, l, r):
    if l == 1 and r == tabs:
        return 0
    if l == 1:
        return abs(pointer - r) + 1
    if r == tabs:
        return abs(pointer - l) + 1
    
    dist_r = abs(pointer - r)
    dist_l = abs(pointer - l)
    
    return min(dist_l, dist_r) + r-l + 2
    
    
if __name__ == "__main__":
    tabs, pointer, l, r = input().strip().split(' ')
    tabs, pointer, l, r = [int(tabs), int(pointer), int(l), int(r)]
    print(solution(tabs, pointer, l, r))
