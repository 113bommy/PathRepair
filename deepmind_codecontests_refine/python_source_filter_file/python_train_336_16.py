n = int(input().strip())
mod = 10**9+7
# import sys
# # sys.setrecursionlimit(10**9)
# def power(num):
#     if num==1: return 1
#     else: return (power(num-1)*2)%mod

# def fac(num):
#     if num==1: return 1
#     else: return (fac(num-1)*num)%mod
# n=583291
power = 1
fac = 1
for i in range(2, n+1):
    power = (power*2)%mod
    fac = (fac*i)%mod
print(fac-power)

# print([fac(n)-power(n) for n in [1,2,3,4,583291]])
# print(power(583291))
# print(fac(583291))
# print()