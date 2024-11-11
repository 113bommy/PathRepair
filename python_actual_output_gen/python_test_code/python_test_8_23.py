n = int(input())
for x in range(0,n,+1):
    s,a,b,c = map(int,input().split())
    wyn = 0
    f = 0
    wyn += int(s/c)
    f = int(s/a)
    wyn +=f*b
    print(wyn)