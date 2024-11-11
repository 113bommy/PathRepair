n=int(input())
for i in range(n):
    b=input()
    s=set(list(map(int,input().split())))
    print(max(1,len(s)-1))