def fun(ls):
    a,b=ls
    if(b>=2*a):
        print(a,2*a)
    else:
        print(-1,-1)




          

    


T = int(input())
# T=1
for _ in range(T):
    # var=input()
    # st=input()
    # val=int(input())
    # ks= list(map(int, input().split()))
    # ls= list(map(int, input().split()))
    # n=int(input())
    # st=input()
    ls= list(map(int, input().split()))
    fun(ls)
