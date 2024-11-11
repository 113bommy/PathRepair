N=input()
if int(N)%10==0:
    print(10)
else:
    ans = 0
    for i in range(len(N)):
        ans+= int(N[i])
        print(ans)
