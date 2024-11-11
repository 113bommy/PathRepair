prime=[2,3,5,7,11]

def create_list(n):
    global prime
    for x in range(prime[-1]+2,n+1,2):
        notPrime=False
        hold=int(x**0.5)+1
        for j in prime:
            if j>hold:
                break
            if x%j==0:
                notPrime=True
                break
        if notPrime==False:
            prime.append(x)
    #print(len(prime))

def factors(n,inc):
    z = 2
    while z*z<= n:
        if n%z==0:
            hold=n
            while (n%z==0):
                n//=z
            if hold//n not in inc:
                inc.append(hold//n)
        z+=1
    if n>1 and n not in inc:inc.append(n)
    return inc

def main():
    mode="filee"
    if mode=="file":f=open("test.txt","r")
    #f.readline()
    #input()
    get = lambda :[int(x) for x in (f.readline() if mode=="file" else input()).split()]
    [n]=get()
    create_list(n)
    if n==1:
        print("0")
        return
    if n==2:
        print("1\n2")
        return
    inc=[]
    for i in range(2,n+1):
        if i in inc:
            continue
        if i in prime:
            inc.append(i)
            continue
        inc=factors(i,inc)
    print(len(inc))
    for i in inc:
        print(i,end=' ')

    if mode=="file":f.close()


if __name__=="__main__":
    main()
