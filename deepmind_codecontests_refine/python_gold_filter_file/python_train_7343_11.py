import sys, bisect
#sys.stdin = open("apples.in","r")
#sys.stdout = open("apples.out","w")

n = int(input())
lst = list(map(int, sys.stdin.readline().split()))
num = [0 for i in range(n)]
for i in range(n):
    num[i] = lst[i]
num.sort(reverse = True)

for i in range(n):
    for j in range(n-i):
        if (lst[j] == num[i]):
            a = j
            break
    for j in range(a, n-i-1):
        print(j+1,j+2)
        lst[j], lst[j+1] = lst[j+1], lst[j]


        
#sys.stdin.close()
#sys.stdout.close()