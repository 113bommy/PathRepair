from collections import Counter
n=int(input())
l=list(map(int,input().split()))
l.sort(reverse=True)
d=Counter(l)
if(d[l[0]]%2==1):
    print("Conan")
else:
    for i in range(1,n):
        if(d[l[i]]%2==1):
            print("Conan")
            exit()
    print("Agasa")