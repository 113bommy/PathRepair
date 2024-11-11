import math
import sys
 
def main():
    
    def find(n):
        # print(n,n)
        a=int(math.sqrt(n/2))
        # print(a,n)
        if a==0:
            print(a)
        else:
            while 2*(a**2 + a) +1 > n: 
                a-=1
            while 2*(a**2 + a) +1 <= n:
                a+=1
            a-=1
            print(a)

            
    
    input = sys.stdin.readline
    i=int(input())
    
    for _ in range(i):
        n=int(input())
        # n = map(int, input().split())
        find(n)
    # n=int(input())
    #         listt = list(map(int, input().split())) 
    # print(find(l,r)==1000000000000000422)
    # n=int(input())
    # for _ in range(n):
    #     l,r = map(int, input().split())
    #     print(find(l,r))
        
 



 
if __name__ == '__main__':
    main()
