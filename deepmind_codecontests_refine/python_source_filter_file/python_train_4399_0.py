import sys

def MI(): return map(int, sys.stdin.readline().split())
def SI(): return sys.stdin.readline()[:-1]

def main():
    inf=10**9
    h,w,t=MI()
    aa=[[int(c) for c in SI()] for _ in range(h)]

    bb=[[0]*w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            ind=True
            if i-1>=0 and aa[i][j]==aa[i-1][j]:ind=False
            if i+1<h and aa[i][j]==aa[i+1][j]:ind=False
            if j-1>=0 and aa[i][j]==aa[i][j-1]:ind=False
            if j+1<w and aa[i][j]==aa[i][j+1]:ind=False
            if ind:bb[i][j]=inf

    for i in range(h):
        for j in range(1,w):
            if bb[i][j]==0:continue
            bb[i][j]=min(bb[i][j-1]+1,bb[i][j])
        for j in range(w-2,-1,-1):
            if bb[i][j]==0:continue
            bb[i][j]=min(bb[i][j+1]+1,bb[i][j])
    for j in range(w):
        for i in range(1,h):
            if bb[i][j]==0:continue
            bb[i][j]=min(bb[i-1][j]+1,bb[i][j])
        for i in range(h-2,-1,-1):
            if bb[i][j]==0:continue
            bb[i][j]=min(bb[i+1][j]+1,bb[i][j])

    for _ in range(t):
        i,j,p=MI()
        i,j=i-1,j-1
        p -= bb[i][j]
        if p<=0:print(aa[i][j])
        else:
            rev=p%2
            print(aa[i][j]^rev)

main()