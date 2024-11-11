import math

def main():
    lB = 1
    rB = 1000000
    midP = (rB + lB)/2
    n = int(input())
    nums = str(input()).split()
    maxL = 0
    for s in nums:
        p = int(s)
        l = 0
        if p > midP:
            l = rB - p
        else:
            l = p - lB
        
        if l > maxL:
            maxL = l
    
    print(l)



main()