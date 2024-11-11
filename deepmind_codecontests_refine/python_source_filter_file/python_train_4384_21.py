w,h,k=map(int,input().split())
n=0
for i in range(k):
    n+=2*(w+h-2)
    w-=2
    h+=2
print(n)
