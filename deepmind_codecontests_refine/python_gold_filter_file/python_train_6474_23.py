n, m = [int(i) for i in input().split()]
mod = 1000000007
print(pow( ( pow(2, m, mod) -1) , n, mod))