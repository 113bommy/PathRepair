import sys
input = sys.stdin.readline
def answer():
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    m = a[0]
    for i in range((n+1)//2):
        print(a[i+1],m)
    return
    
    
for _ in range(int(input())):
    answer()