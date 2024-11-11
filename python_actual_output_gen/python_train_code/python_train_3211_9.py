n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
maxi1 = 0
maxi2 = 0
maxi = 0
for beg in range(n):
    tmp1 = a[beg]
    tmp2 = b[beg]
    for end in range(beg+1,n):
        tmp1 = tmp1 | a[end]
        tmp2 = tmp2 | b[end]
    
        if tmp1 + tmp2 > maxi: maxi = tmp1 + tmp2
    #if tmp1 + tmp2 > maxi: maxi = tmp1 + tmp2
    #if tmp2 > maxi2: maxi2=tmp2    
print(maxi)