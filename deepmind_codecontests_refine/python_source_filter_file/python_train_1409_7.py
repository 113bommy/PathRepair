from sys import stdin,stdout
from collections import deque
input = stdin.readline
 
def main():
    #t = int(input())
    t=1
    for i in range(t):
        n = int(input())
        #n, k = map(int,input().split())
        #ai = list(map(int,input().split()))
        ans = 0
        d1 = {}
        d2 = {}
        d3 = {}
        for i in range(n):
            x,y = map(int,input().split())
            num = x*1000000001+y
            if num in d3:
                d3[num] += 1
            else:
                d3[num] = 1
            if x in d1:
                d1[x] += 1
            else:
                d1[x] = 1
            if y in d2:
                d2[y] += 1
            else:
                d2[y] = 1
        ans = 0
        for i in d1:
            ans += d1[i]*(d1[i]-1)//2
        for i in d2:
            ans += d2[i]*(d2[i]-1)//2
        for i in d3:
            ans -= d3[i]*(d3[i]-1)//2
        print(ans)
main()
