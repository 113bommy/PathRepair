import sys


def input(): return sys.stdin.readline().rstrip()


for _ in range(int(input())):
    n=int(input())
    s=input()

    arr = []
    for k in range(0,n):
        if n%2==0:
            if k%2==1:
                ns = s[k:] + s[:k][::-1]
            else:
                ns = s[k:] + s[:k]
        else:
            if k%2==0:
                ns = s[k:] + s[:k][::-1]
            else:
                ns = s[k:] + s[:k]
        arr.append((ns, k+1))
    
    arr.sort(key=lambda x:x[0])
    print(arr[0][0])
    print(arr[0][1])