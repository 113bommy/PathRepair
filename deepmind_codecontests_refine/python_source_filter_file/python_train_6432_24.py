N=int(input())
lst=list(map(int,input().split()))
P=round(lst/N)
print(sum[(i-P)**2 for i in lst])