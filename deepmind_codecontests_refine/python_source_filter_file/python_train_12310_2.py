import sys
input = sys.stdin.buffer.readline
def main():
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a.sort()
    b.sort(reverse=True)
    for i in range(n):
        if a[i]<b[i]:
            temp=a[i]
            a[i]=b[i]
            b[i]=temp
        else:
            break
    return sum(a)
    
t=int(input())
while t:
    t-=1
    print(main())  