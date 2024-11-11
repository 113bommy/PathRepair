x, k = map(int,input().split())
if(x == 0):
    print (0)
else:
    end = pow(2,k+1,1000000007)
    sum1 = ((x*end)-(end-2))%1000000007
    sum2 = (sum1+(pow(2,k,1000000007)-1))%1000000007
    print(sum2)
    