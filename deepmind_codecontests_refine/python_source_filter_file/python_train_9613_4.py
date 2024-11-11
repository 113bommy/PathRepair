n=int(input())
mod=1000000007
print(int((pow(3, n, mod)+3*(-1)**n)/4)%mod)
