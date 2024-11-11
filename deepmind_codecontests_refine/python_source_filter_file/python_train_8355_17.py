from math import sqrt
def factor(d):
    f=[]
    for i in range(1,int(sqrt(d))+1):
        if d%i==0:
            f.append(i)
            if d%(d//i)==0:
                f.append(d//i)
            
            continue
    return f

def main():
    for _ in range(int(input())):
        n,x,y=map(int,input().split( ))
        d=y-x
        f=factor(d)
        for d in sorted(f):
            t=n
            k=0
            check=False
            ans=[]
            while t:
                first=y-k*d
                if first<0:
                    break
                ans.append(first)
                if first==x:
                    check=True
                t-=1
                k+=1
            if not check:
                continue
            if t:
                k=1
                while t:
                    ans.append(y+k*d)
                    t-=1
                    k+=1
            print(*ans)
            break
main()