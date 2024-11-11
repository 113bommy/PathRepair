if __name__=='__main__':
    inp = input()
    arr = inp.split(' ')
    L = [int(x) for x in arr]
    ans = [0,0,0]
    s = 0
    for l in L:
        s+=l
    imp = False
    for l in L:
        if l>s/2:
            imp = True
    if imp:
        print('Impossible')
    else:
##        m = min(L)//2
##        for i in (0,1,2):
##            ans[i]+=m
##            L[i]-=m*2
####        print(ans)
        imp = False
        if L[0]==min(L):
            if L[1]>L[2]:
                bonds = L[1]-L[2]
                ans[0] += bonds
                L[0]-= bonds
                L[1] -=bonds
            else:
                bonds = L[2]-L[1]
                ans[2] += bonds
                L[0] -= bonds
                L[2] -= bonds
            if L[0]%2==1:
                imp = True
            else:
                bonds = L[0]//2
                ans[0] += bonds
                ans[2] += bonds
                ans[1] += (L[1]+L[2])//2 - bonds
        elif L[1]==min(L):
            if L[0]>L[2]:
                bonds = L[0]-L[2]
                ans[0] += bonds
                L[1]-= bonds
                L[0] -= bonds
            else:
                bonds = L[2]-L[0]
                ans[1] += bonds
                L[1] -= bonds
                L[2] -= bonds 
            if L[1]%2==1:
                imp = True
            else:
                bonds = L[1]//2
                ans[0] += bonds
                ans[1] += bonds
                ans[2] += (L[0]+L[2])//2 - bonds

        else:
            if L[0]>L[1]:
                bonds = L[0]-L[1]
                ans[2] += bonds
                L[2]-= bonds
                L[0]-=bonds
            else:
                bonds = L[1]-L[0]
                ans[1] += bonds
                L[2] -= bonds
                L[1] -= bonds
            if L[2]%2==1:
                imp = True
            else:
                bonds = L[2]//2
                ans[2] += bonds
                ans[1] += bonds
                ans[0] += (L[0]+L[1])//2 - bonds
            
        for i in ans:
            if i<0:
                imp = True
        if imp:
            print('Impossible')
        else:
            for i in range(3):
                print(ans[i],end=' ')
            print()
