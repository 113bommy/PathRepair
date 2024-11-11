import sys
input = sys.stdin.buffer.readline

for t in range(int(input())):
    n,l,r = map(int,input().split())
    for i in range(l,min(2*(n-2)+1,r) + 1):
        print('1' if i & 1 else i//2 + 1 , end = ' ')
    n_set = n
    set_idx = 2*(n-2) + 2
    
    while(n_set > 2):
        ls = l - set_idx + 1
        rs = r - set_idx + 1
        set_idx += 2*(n_set - 2)
        set_par = n - n_set + 2
        if ls < 2 and rs > 1:print(n , end = ' ')
        for i in range(max(2,ls) , min(2*(n_set - 2),rs) + 1):
            print(set_par + (i-1)//2 if i & 1 else set_par , end = ' ')
        n_set -= 1
    l -= set_idx
    r -= set_idx
    if l <= 0 and r>=0:print(n , end = ' ')
    if r == 1:         print(1 , end = ' ')
    print()
    
