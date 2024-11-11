n,w=input().split()
w=int(w)

a=input().split()

ans=True

pas=0
lim_pas=w
for elem in a:
    if ans:
        pas=pas+int(elem)
        if pas>w:
            print (-1)
            ans=False
            break
        else:
            if pas<0:
                lim_pas=lim_pas+pas
                pas=0
                if lim_pas<0:
                    print (-1)
                    ans=False
                    break
        lim_pas=min(lim_pas,w-pas) 

if ans:
   print (lim_pas+1)
    
