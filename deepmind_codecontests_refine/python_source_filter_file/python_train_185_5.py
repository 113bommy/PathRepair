n,p= map(int,input().split())
for i in range(round(p**(1/n))+1,0,-1):
    if p%(i**n)==0:
        print(i)
        exit()