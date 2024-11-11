#Amirhossein Alimirzaei
#@HajLorenzo

input()
_=list(set(sorted(list(map(int,input().split())))))
__=0
___=0
for i in range(len(_)-1):
    if _[__+1]-_[__] in range(1,3):
        ___+=1
    else:
        ___=0
    if ___==2:
        if _[__+1]-_[__-1] in range(1,3):
            print("YES")
            exit()
        else:
            ___=0
    __+=1
print("NO")
#in site time: 1:32

'''Look, if you had, one shot, or one opportunity
To seize everything you ever wanted - one moment
Would you capture it? Or just let it slip?
Yo'''