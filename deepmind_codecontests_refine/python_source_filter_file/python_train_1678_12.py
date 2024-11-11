n = int(input())
for i in range(n):
    l,v,r,d=map(int,input().split())
    print(l//v-r//v+(l-1)//v)