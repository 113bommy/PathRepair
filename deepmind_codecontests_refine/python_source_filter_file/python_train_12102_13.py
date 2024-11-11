T=int(input())

def beautiful_array():
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    
    s1=set(arr)
    if(len(s1)>k):
        print('-1')
    else:
        ls=list(s1)
        while(len(ls)<k):
            ls.append(1)
        print(2*len(ls))
        for i in range(2):
            for j in range(len(ls)):
                print(ls[j],end=' ')
        print()

while T>0:
    beautiful_array()
    T -=1