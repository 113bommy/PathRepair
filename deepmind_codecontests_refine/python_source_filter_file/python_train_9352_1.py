import sys
readline=sys.stdin.readline
read=sys.stdin.read

def main():
    n,k=map(int,readline().split())
    ab=[list(map(int,l.split())) for l in read().splitlines()]
    
    ek=0
    while k>>ek:
        ek+=1
    ans=0
    for i in range(ek):
        if k>>i&1:
            m=(k>>(i+1))<<(i+1)|((1<<i)-1)
            ans=max(ans,sum([e[1] for e in ab if e[0]|m==m]))
    ans=max(ans,sum([e[1] for e in ab if e[0]|k==k]))
    print(max(cand))

if __name__=='__main__':
    main()
