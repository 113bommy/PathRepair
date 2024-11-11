if(__name__=='__main__'):
    n1,n2,k1,k2=map(int,input().split())
    if(n1==n2):
        print("Secnod")
    else:
        print("First" if n1>n2 else "Second")
