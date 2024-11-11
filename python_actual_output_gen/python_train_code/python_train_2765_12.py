import sys,os.path
if __name__ == '__main__':
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    n = int(input())
    x = int(input())
    flag = True
    for i in range(n):
        a,b = map(int,input().split())
        if a==x or b==x or 6-a==x or 6-b==x:
            flag = False
        else:
            x = 6-x
    if flag:
        print("YES")
    else:
        print("NO")