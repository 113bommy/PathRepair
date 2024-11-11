import sys,math

def func(n,m,q):
    if m==1:
        return n
    x=m//2
    if x+1==q:
        return n%2
    else:
        if q>x+1:
            q-=(x+1)
        return func(n//2,m//2,q)


def main():

    n,l,r=map(int,sys.stdin.readline().strip().split())

    count=0

    if n>=1:
        m=2**(int(math.log(n,2))+1)-1
        for i in range(l,r+1):
            if func(n,m,i)==1:
                count+=1

    sys.stdout.write(str(count)+'\n')


main()