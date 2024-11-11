n=int(input())
di={}
for i in range(n):
    di[input()]=n+1-i
#d={value:key for key, value in di.items()}
for i in di:
    print("\n".join(sorted(di,key=lambda  x:di[x])))