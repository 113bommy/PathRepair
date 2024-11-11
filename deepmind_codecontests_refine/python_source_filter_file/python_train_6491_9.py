# from scipy.special import comb,perm
# import math
# x=1-2*(0.1587)
# for i in range(1,10):
#     print(1-(1-x)**i)
p,d=map(int,input().split())
ma=p+1
mi=p-d
part=1
ans=0
if d==0:
    print(p)
    exit()
# if p<10 and d<10:
#     print(p)
#     exit()
while  (ma//part)!=(mi//part) :
    part*=10
# print(part)
if part==10:
    ans=p
# elif part>=ma :
    # ans+=(((p%part)//(part//10))-1)*(part//10)
    # ans=(part//10)-1
else:
    ans+=(p//part)*part
    # print(ans)
    ans+=(((p%part)//(part//10))-1)*(part//10)
    # print(ans)
    part//=10
    ans+=part-1
print(ans)