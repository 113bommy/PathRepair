if __name__=='__main__':
    n,k,l,c,d,p,nl,np=map(int, input().split())
    drink=k*l
    x=min(drink/nl,d,p/np)
    print(int(x//n))