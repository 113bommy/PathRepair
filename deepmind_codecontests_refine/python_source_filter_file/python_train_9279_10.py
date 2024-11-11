from sys import stdin,stdout
input = stdin.readline
 
def main():
    #t = int(input())
    t=1
    for i in range(t):
        #n = int(input())
        #n, m = map(int,input().split())
        #ai = list(map(int,input().split()))
        n, x, y = map(int,input().split())
        ans = [1] * n
        if n > y or (y-n+1)**2 < x:
            print(-1)
            return
        print(y-n+1)
        for i in range(n-1):
            print(1)
main()

