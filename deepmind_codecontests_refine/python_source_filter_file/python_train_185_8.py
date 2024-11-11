n,p= map(int,input().split())
for i in range(int(p**(1/n)),0,-1):
    if p%(i**n)==0:
        print(i)
        exit()