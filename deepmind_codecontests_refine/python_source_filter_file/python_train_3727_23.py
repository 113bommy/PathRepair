import sys
import heapq

def main():
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))

    h=[]
    for i in range(n):
        if b[i]>a[i]:
            heapq.heappush(h,[b[i]*-1,i])

    loop=0
    idx=0
    while(1):
    #print(b)
        if not h:
            break
        buf,idx=heapq.heappop(h)
        buf=-1*buf

        x=(buf-a[idx])//(b[(idx-1)%n]+b[(idx+1)%n])
        buf-=x*(b[(idx-1)%n]+b[(idx+1)%n])
        loop+=x
        b[idx]=buf
        if x==0:
            #print(b)
            print(-1)
            sys.exit()
        elif buf>a[idx]:
            heapq.heappush(h,[buf*-1,idx])

    print(loop)

if __name__ == '__main__':
    main()