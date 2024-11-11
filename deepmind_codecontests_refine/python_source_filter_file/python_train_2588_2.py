#すぬけくんの塗り絵
h,w,n=map(int,input().split())
dic={}
for  _ in range(n):
    a,b=map(int,input().split())
    for i in range(a-1,a+2):
        for j in range(b-1,b+2):
            if (i,j) in dic.keys():
                dic[(i,j)]+=1
            else:
                dic[(i,j)]=1
              
howmany=[0 for i in range(10)]
for some in dic.keys():
    a,b=some[0],some[1]
    if 2<=a<=h-1 and 2<=b<=w-1:
        howmany[dic[some]]+=1
J=(h-2)*(w-2)-sum(howmany)
print(J)
for i in range(1,10):
    print(howmany[i])