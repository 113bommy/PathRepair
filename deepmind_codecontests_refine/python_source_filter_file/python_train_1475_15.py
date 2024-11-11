n=int(input())
a=list(map(int,input().strip().split(" ")))
a.sort()
pp=0
for i in range(n):
    if a[i]>=pp:
        pp+=1
print(pp)
        

        
