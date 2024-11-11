#! /usr/bin/env python3

'''
def ceil(n,k):
    if not n%k:
        return n/k
    else:
        return int(n/k)+1
'''

if __name__ == '__main__':
    tmp1 = input().split()
    n, m, k = int(tmp1[0]),int(tmp1[1]),int(tmp1[2])
    tmpp = input().split()
    now = 0
    cnt = 0
    page = 0
    i = 0
    while i < m:
        if now < int(tmpp[i]):
            now += ((int(tmpp[i])-now-1)//k+1) * k
        while i < m and int(tmpp[i]) <= now:
            i += 1
            page += 1
        now += page
        page = 0
        cnt += 1
    print(cnt)