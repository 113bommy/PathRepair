from sys import stdin,stdout
input = stdin.readline
 
def main():
    #t = int(input())
    t=1
    for i in range(t):
        #n = int(input())
        #n, m = map(int,input().split())
        #ai = list(map(int,input().split()))
        h1, h2 = map(int,input().split())
        a, b = map(int,input().split())
        h1 = 8 * a + h1
        if h1 > h2:
            print(0)
            return
        if b >= a:
            print(-1)
            return
        ch = a-b
        ch *= 12
        h2 -= h1
        print((h2+ch-1)//ch)
main()

