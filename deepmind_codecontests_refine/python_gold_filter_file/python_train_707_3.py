def main():
    s=set()
    for digit in range(16):
        for i in range(1,1000):
            c=i*10**digit+int('9'*digit or 0)
            if c<10**15:
                s.add(c)
    c=sorted(s)
    for i,n in enumerate(c):
        sn=n/sum(map(int,str(n)))
        for m in c[i+1:i+11]:
            sm=m/sum(map(int,str(m)))
            if sm<sn:
                s.remove(n)
                break
    print(*sorted(s)[:int(input())],sep='\n')
main()