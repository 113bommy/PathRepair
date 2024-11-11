import sys
input = sys.stdin.readline

# 難しい.
# まず、kと2*kの場合を比べることで、k>=n/2が分かる
# x>0のときは、k=nのときが最善.
# x<=0のときは、[start,start+k]と[start,start+k-1]を比較。
# x<=0なので、前者が正なら後者も正
# なので、尺取り風に、大きいkからstart=0から後ろへ順に調べていくことができる。
# （ある[start,start+k]でうまくいかなかったら、一つ小さいkを使う）

n=int(input())
A=list(map(int,input().split()))
x=int(input())

if (n//2)*x+sum(A)>0:
    print(n)
    sys.exit()
if x>0:
    print(-1)
    sys.exit()


B=A+[x]*(n//2)
SUM=sum(B)
start=0
last=n

while True:
    if SUM<=0 and last-start<=n//2:
        print(-1)
        break
        
    elif SUM<=0:
        SUM-=B[last-1]
        last-=1

    else:
        if last==n:
            print(last-start)
            break
        
        SUM-=B[start]
        SUM+=B[last]
        
        start+=1
        last+=1
