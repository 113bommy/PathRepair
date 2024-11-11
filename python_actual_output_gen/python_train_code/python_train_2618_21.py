n=int(input())
l=[]
for i in range(n):
        a=list(map(int,input().split()))
        l.append(a)
for i in l:
        if i[0]<i[1]:
                if int(i[0])*2>=i[1]:
                        print((2*i[0])**2)
                else:
                        print((2*i[1])**2)
        if i[0]>=i[1]:
                if int(i[1])*2>=i[0]:
                        print((2*i[1])**2)
                else:
                        print((2*i[0])**2)
        