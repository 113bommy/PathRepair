n=int(input())
l=input().split()
k=l[-1]
for i in range(len(l)-1,0,-1):
    if l[i] != k:
        print(i + 1)
        break