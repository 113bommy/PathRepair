import sys,os.path
if __name__ == '__main__':
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    n = int(input())
    a = list(map(int,input().split()))
    if n==1:
        for i in range(3):
            if i!=2:
                print('1 1')
                print(0)
            else:
                print('1 1')
                print(-a[0])
    else:
        ans = []
        final = []
        for i in range(0,n):
            if i==0:
                ans.append(0)
            else:
                ans.append(-a[i])
                a[i]-=n*a[i]
            if i!=0:
                final.append(-a[i]//(n-1))
        for i in range(3):
            if i==0:
                print('1 1')
                print(-a[0])
            elif i==1:
                print(f'1 {n}')
                print(*ans)
            else:
                print(f'2 {n}')
                print(*final)
            