import sys,os.path
if __name__ == '__main__':
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    for _ in range(int(input())):
        n,k = map(int,input().split())
        a = [[0 for i in range(n)]for j in range(n)]
        if k%n==0:
            print(0)
        else:
            print(2)
        p = 0
        q = 0
        for i in range(k):
            a[p][q] = 1
            p+=1
            q+=1
            q = q%n
            if p==n:
                p = 0
                q = (q+1)%n
        for i in range(n):
            print(*a[i])


        