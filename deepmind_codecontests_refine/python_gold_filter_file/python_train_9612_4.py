n=int(input())
mod=1000000007
print(int((pow(3, n, 4*mod)+3*(-1)**n)/4)%(4*mod))
