def fun(angle):
    i=3
    # (n-2) *180
    total_angle=180
    given_angle=angle*i
    while(total_angle<given_angle):
            total_angle=(i-2)*180
            given_angle=angle*i
            i+=1
    if(total_angle==given_angle):
        print('Yes')
    else:
        print('No')


        

T = int(input())
# T=1
for i in range(T):
    # var=input()
    # st=input()
    val=int(input())
    # ks= list(map(int, input().split()))
    # ms= list(map(int, input().split()))
    # ls= list(map(int, input().split()))
    fun(val)