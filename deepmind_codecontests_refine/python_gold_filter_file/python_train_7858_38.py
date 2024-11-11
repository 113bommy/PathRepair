a=int(input())
C = [int(x) for x in input().split()]
count=0
mayor=0
for k in range (len(C)-1):
    if C[k]<=C[k+1]:
        count+=1
    else:
        count=0
    if count>mayor:
        mayor=count
print(mayor+1)