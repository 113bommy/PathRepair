import sys,os,io,time,copy,math
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')  


def main():  
    arr=[]
    for i in range(4):
        x=input()
        a=[]
        for s in x:
            a.append(s)
        arr.append(a)
    flag=0
    for i in range(2):
        for j in range(2):
            count_hash=0
            count_dot=0
            if arr[i][j]=='#':
                count_hash+=1
            if arr[i][j+1]=='#':
                count_hash+=1
            if arr[i+1][j]=='#':
                count_hash+=1
            if arr[i+1][j+1]=='#':
                count_hash+=1
            if arr[i][j]=='.':
                count_dot+=1
            if arr[i][j+1]=='.':
                count_dot+=1
            if arr[i+1][j]=='.':
                count_dot+=1
            if arr[i+1][j+1]=='.':
                count_dot+=1
            if count_hash>flag:
                flag=count_hash
            if count_dot>flag:
                flag=count_dot
    if flag>=3:
        print("YES")
    else:
        print("NO")

main()
    