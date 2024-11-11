for i in range(int(input())):
    siz = int(input())
    l = [int(i) for i in input().split()]
    l.sort()
    kl=[]
    
    kl1 = l[:siz//2]
    kl2 = l[siz-1:siz//2-1:-1]#> part
    #print(kl1, kl2)
    
    
    for i in range((siz)//2):
        kl.append(kl2[i])
        kl.append(kl1[i])
    if siz%2:
        #t = siz//2
        kl.append(l[(siz+1)//2]-1)
    kl = kl[::-1]
    kl = [str(i) for i in kl]
    print(" ".join(kl))
    
