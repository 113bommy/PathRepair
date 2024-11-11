import sys
input=sys.stdin.readline
def main():
    A,B,C,D=map(int,input().split())
    mx=A
    my=C
    mz=C
    iv=0
    val=0
    for i in range(1,B+1):
        val=val+(C-my+1)*(B-max(i,A)+1)
        if (mz+1>D):
            C=C-1
        my=max(my-1,B)
        mz=mz+1

        if (C<=B):
            break

    print(val)
        
main()

