from typing import Counter


for _ in range(int(input())):
    n=int(input())
    s=input()
    flag=0
    for i in range(n-1):
        for j in range(i+1,n):
            if s[i:j+1].count('a')==s[i:j+1].count('b'):
                print(i+1,j+1)
                flag=1
                break
        if flag==1:
            break
    if flag==0:
        print("-1 -1")